#define DIRECTINPUT_VERSION		0x0800

#include <windows.h>
#include <stdint.h>
#include <math.h>
#include "patch.h"
#include "OggPlayer.h"
#include "resource.h"
#include "globals.h"
#include "DXFont.h"

char clientVer[4] = { 2, 3, 1, 'b' };
char logItBuf[0x400];

int resW = 1280;
int resH = 720;
float drawDistanceMultiplier = 1.0f;
int fullScreen = 0;
int skipWarning = 0;
unsigned char* itemFile;
int itemFileSize = 0;
float UIdividerX = 20.0f;
float UIdividerY = 20.0f;
float UIscaleX = 0.05f;
float UIscaleY = 0.05f;
int itemUseDialogX = 56;
int itemUseDialogY = 80;

SHAREDSPACE SharedSpace;

// DirectX 8 Stuff
HFONT bgmHFont = CreateFontA(
	-10,
	0,
	0,
	0,
	FW_DONTCARE,
	0,
	0,
	0,
	SHIFTJIS_CHARSET,
	OUT_DEFAULT_PRECIS,
	CLIP_DEFAULT_PRECIS,
	CLEARTYPE_QUALITY,	// Looks much better
	DEFAULT_PITCH,
	(char*)(0x006302B8) // TEXT("ＭＳ ゴシック") - From client encoded in Shift JIS
);
LPDIRECT3DDEVICE8 dx = NULL;
DXFont* BGMTrackFont = new DXFont(CreateFontA(12, 6, 0, 0, FW_DONTCARE, 0, 0, 0, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FIXED_PITCH, (char*)0x006302B8));
DXFont* PositionFont = new DXFont(CreateFontA(18, 9, 0, 0, FW_BOLD, 0, 0, 0, SHIFTJIS_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FIXED_PITCH, (char*)0x006302B8));

// BGM Values
OggPlayer* op = nullptr;
int shuffleBGM = 0;
char* BGMVol;
char lastBGMVol = 0;
int lastBGM = -1;
bool changeOgg = false;
int changeToPlaylist = 0;
HWND* hwnd = NULL;
bool closeCheck = false;
bool runGameLoop = false;

// ASM Values
int _EAX, _ECX, _EDX, _EBX, _EDI, _ESI;
float float1, float2, float3, float4, float5;
int int1, int2;
float *_a1 = nullptr;
float *_a2 = nullptr;
float *_a3 = nullptr;
char textBuf[0x1000];
unsigned int isClosed = 0;

// DINPUT Values
char deadZonePercent = 5;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	// Load Item data from DLL
	HRSRC hResInfo = FindResource(hModule, MAKEINTRESOURCE(IDR_ITEM), L"ITEMFILE");
	if (hResInfo != NULL)
	{
		itemFile = (unsigned char*)LoadResource(hModule, hResInfo);
		itemFileSize = SizeofResource(hModule, hResInfo);
		// If not found use data in EXE
		if (itemFile == nullptr) itemFile = (unsigned char*)0x696538;
		if (itemFileSize == 0) itemFileSize = 0xA30E;
	}
	else
	{
		itemFile = (unsigned char*)0x696538;
		itemFileSize = 0xA30E;
	}
	
	BGMVol = (char*)0x6F4E50;
	
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		//_CrtSetBreakAlloc(1074);

		readRegistry();
		if (op == nullptr) {
			op = new OggPlayer(30, shuffleBGM ? true : false);
			op->SetVolume((int)(*BGMVol + 15));
		}
		setStrings();
		fixResolutionChoice();
		setResolution();
		setDrawDistance();
		patchClient();
		
		// Load offline DLL
		HINSTANCE hOfflineDLL = LoadLibraryEx(L"offline.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
		if (hOfflineDLL == NULL)
		{
			// If offline isn't found load Peer 2 Peer DLL (Future)
			HINSTANCE hP2PDLL = LoadLibraryEx(L"p2p.dll", NULL, LOAD_LIBRARY_SEARCH_APPLICATION_DIR);
		}
	}
	break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}