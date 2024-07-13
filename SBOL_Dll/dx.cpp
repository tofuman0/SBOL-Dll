#include "dx.h"
#include "asm.h"

extern int resW;
extern int resH;
extern OggPlayer* op;
extern LPDIRECT3DDEVICE8 dx;
extern DXFont* BGMTrackFont;
extern int _EAX, _ECX, _EDX, _EBX, _EDI, _ESI;

HRESULT __stdcall directxCustom()
{
	if (dx)
	{
		if (BGMTrackFont->CheckDevice() != S_OK)
		{
			HRESULT hr = BGMTrackFont->InitDeviceObjects(dx);
#ifdef _DEBUG
			if (hr != S_OK)
				OutputDebugStringA("Failed to create font!\n");
#endif
			return hr;
		}
		else
		{
			// Current track string on UI
			if (*(int*)0x006EC81C != NULL)
			{
				drawBGMString();
			}
#ifdef _DEBUG
			// Position debug string
			if (*(int*)0x006EBE4C != NULL) // Pointer set if in course
			{
				drawPositionString();
			}
#endif
		}
		return dx->EndScene();
	}
	return D3DERR_INVALIDDEVICE;
}
void drawBGMString()
{
	char battleStatus = *(char*)(*(int*)0x006EC81C + 0xF0);
	if (battleStatus == 0 ||
		battleStatus == 6 ||
		battleStatus == 7) // If not in battle
	{
		int y = resH - 150;
		if (*(int*)(0x006F4E48) == 2)
			y = resH - 16;
		char bgmInfo[0x100];
		sprintf_s(bgmInfo, sizeof(bgmInfo), "CURRENT TRACK: %s", op->GetTrackName());
		HRESULT hr = S_OK;
		hr = BGMTrackFont->DrawText(8, (float)y, 0xFFBBBB99, bgmInfo, 0);
#ifdef _DEBUG
		if (hr != S_OK)
			OutputDebugStringA("Failed draw text!\n");
#endif
	}
}
void drawPositionString()
{
	char battleStatus = *(char*)(*(int*)0x006EC81C + 0xF0);
	if (battleStatus == 0 ||
		battleStatus == 6 ||
		battleStatus == 7) // If not in battle
	{
		unsigned short location1 = *(unsigned short*)(*(int*)(*(int*)(*(int*)0x006EBE4C + 0x118) + 0x3EC) + 0x20);
		unsigned short junction = *(unsigned short*)(*(int*)(*(int*)(*(int*)0x006EBE4C + 0x118) + 0x3EC) + 0x18);
		unsigned short distance = *(unsigned short*)(*(int*)(*(int*)(*(int*)0x006EBE4C + 0x118) + 0x3EC) + 0x1C);

		int y = resH - 230;
		if (*(int*)(0x006F4E48) == 2)
			y = resH - 32;
		char posInfo[0x100];
		sprintf_s(posInfo, sizeof(posInfo), "POSITION: %04X:%04X:%04X", location1, junction, distance);
		HRESULT hr = S_OK;
		hr = BGMTrackFont->DrawText(8, (float)y, 0xFFBBBB99, posInfo, 0);
		if (hr != S_OK)
			OutputDebugStringA("Failed draw text!\n");
	}
}