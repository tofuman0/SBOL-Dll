#include "patch.h"
#include "resolution.h"
#include "strings.h"

extern char clientVer[3];
extern char logItBuf[0x400];
extern int resW;
extern int resH;
extern int fullScreen;
extern int skipWarning;
extern unsigned char* itemFile;
extern int itemFileSize;
extern float UIdividerX;
extern float UIdividerY;
extern float UIscaleX;
extern float UIscaleY;
extern int itemUseDialogX;
extern int itemUseDialogY;
extern bool closeCheck;
extern HWND* hwnd;

// BGM Values
extern OggPlayer* op;
extern int shuffleBGM;
extern char* BGMVol;
extern char lastBGMVol;
extern int lastBGM;
extern bool changeOgg;
extern int changeToPlaylist;

// DINPUT Values
extern char deadZonePercent;

// DirectX 8 Values
extern LPDIRECT3DDEVICE8 dx;
extern DXFont* BGMTrackFont;

void patchClient()
{
	// FPS (60 Default)
	//*(char*)0x0041BD84 = 60;

	// Car Detail
	//*(char*)0x00503C1C = 0x03;

	// Window Style
	*(int*)0x0041C512 = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	*(int*)0x0041C49D = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	// Version - We replace the sprintf function and ignore the values pushed and use our own and return the buffer from sprintf in VerString function.
	insertFunction(0x0043B919, VerString, 5, FT_CALL);
	//*(char*)0x43963d = clientVer[2]; // 2.3 requires more work as it pushes a xor'd register ebx
	//*(char*)0x0043B90C = clientVer[1];
	//*(char*)0x0043B90E = clientVer[0];

	// Connection Version Change from SB 0x7B to TM 0x01
	//*(char*)0x0043C4F7 = 'T';
	//*(char*)0x004AB7A4 = 'T';
	//*(char*)0x0043C502 = 'M';
	//*(char*)0x004AB7AF = 'M';
	//*(char*)0x0043C50B = 0x01;
	//*(char*)0x004AB7B8 = 0x01;

	// Server IP
	*(char**)0x0042818D = defaultIP;
	*(char**)0x00428192 = defaultIP + 0x04;
	*(char**)0x00428198 = defaultIP + 0x08;
	*(char**)0x004281A5 = defaultIP + 0x0C;
	*(char**)0x004281FB = defaultServerName;

	// Use registry to check for full screen and skip warning
	insertFunction(0x00418DF1, fullScreenMode, 10, FT_CALL);
	insertFunction(0x00426FA5, skipBootWarning, 8, FT_CALL);
	NOPSpace(0x00426F9B, 5);

	// Multiclient
	*(unsigned char*)0x0041C0BE = 0xEB;

	// Log and close Bug Fix
	_beginthread(windowMonitorThread, 0, NULL);
	insertFunction((int)0x0041C1C7, exitFix, 6, FT_JUMP);

	// Use Icon from Game EXE
	*(int*)0x0041C58C = 0x104;
	*(int*)0x0041C5A0 = (int)clientName;
	*(int*)0x0041C5BF = 0x104;
	*(int*)0x0041C5D5 = (int)clientName;
	
	// Speed Limit (111.11f by default)
	*(float*)0x0060652C = 166.66f;
	*(float*)0x0060C3D4 = 166.66f;

	// Item dat file
	*(unsigned char**)0x004388B9 = itemFile;
	*(unsigned char**)0x0045E5A7 = itemFile;
	*(unsigned char**)0x00496D42 = itemFile;
	*(unsigned char**)0x00496D49 = itemFile;
	*(unsigned char**)0x00496DCD = itemFile;
	*(unsigned char**)0x00496DD4 = itemFile;
	*(unsigned char**)0x004DB9FF = itemFile;
	*(unsigned char**)0x004DBA06 = itemFile;
	*(unsigned char**)0x00503208 = itemFile;
	*(unsigned char**)0x0050322B = itemFile;
	*(unsigned char**)0x00503232 = itemFile;

	*(unsigned char**)0x00438893 = itemFile + 0x04;
	*(unsigned char**)0x004388A3 = itemFile + 0x636;

	*(unsigned char**)0x0045F161 = itemFile + 0x07;

	*(unsigned char**)0x0042568F = itemFile + 0x0A;
	*(unsigned char**)0x004256E5 = itemFile + 0x0A;
	*(unsigned char**)0x00425723 = itemFile + 0x0A;

	*(unsigned char**)0x00425689 = itemFile + 0x0B;
	*(unsigned char**)0x004256DE = itemFile + 0x0B;

	*(unsigned char**)0x0049692F = itemFile + 0x0E;
	*(unsigned char**)0x00496CFE = itemFile + 0x0E;

	*(unsigned char**)0x00503216 = itemFile + itemFileSize;

	// Increase Type Limit in part ticket exchange (default is 6)
	*(unsigned char*)0x00466367 = 0x0A;
	// Increase Type Limit in part shop (default is 6)
	*(unsigned char*)0x0045EBB9 = 0x0A;

#ifdef DEBUG_LOG
	//NOPSpace(0x00512744, 5);
	//insertFunction((int)0x0051FA04, debugLog, 5, FT_CALL);
	//insertFunction((int)0x0041C2AA, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0041C364, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0041BE19, debugIt, 5, FT_CALL); // FPS
	//insertFunction((int)0x0042720B, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0042FE39, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00430B57, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00430BAB, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00437616, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00437968, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00446C12, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0044A810, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0044A8FC, debugIt, 5, FT_CALL);
	//insertFunction((int)0x0044A9FB, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00492C42, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004C0406, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004CCECA, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004D06CB, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004D6B58, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004CCECA, debugIt, 5, FT_CALL);
	//insertFunction((int)0x004D8C5C, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00526590, debugIt, 5, FT_CALL);
	//insertFunction((int)0x005275DD, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527712, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527931, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527AA2, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527BB8, debugIt, 5, FT_CALL);
	//insertFunction((int)0x00527D00, debugIt, 5, FT_CALL);
	//setFunction(0x6F7A24, Log);
	//*(int*)(0x6F7A24) = (int)Log;
	//*(char*)0x006F7710 = 0; // enable log 1 - Action Script
	//*(char*)0x006F7711 = 0; // enable log 2 - General
#endif

	// BGM Stuff
	insertFunction((int)(0x004F2530 + 0x9B), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x128), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x197), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x206), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x241), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x2C4), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x2F3), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x322), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x351), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x384), setBGM, 5, FT_CALL);
	insertFunction((int)(0x004F2530 + 0x3C5), setBGM, 5, FT_CALL);
	*(int*)(0x004F29F0) = (int)stopBGMasm;
	// Create playlists
	op->GeneratePlaylist("data\\bgm", "freerun*.ogg", 0);
	op->GeneratePlaylist("data\\bgm", "battle_*.ogg", 1);
	op->GeneratePlaylist("data\\bgm", "battlewin*.ogg", 2);
	op->GeneratePlaylist("data\\bgm", "battleend*.ogg", 3);
	op->GeneratePlaylist("data\\bgm", "battlelose*.ogg", 4);
	op->GeneratePlaylist("data\\bgm", "mainmenu*.ogg", 5);
	op->GeneratePlaylist("data\\bgm", "garage*.ogg", 6);
	op->GeneratePlaylist("data\\bgm", "parking*.ogg", 7);
	_beginthread(oggThread, 0, NULL);

	// Login Screen BGM
	//*(char*)0x0043DC24 = 0x07; // Mainmenu.wav (0x0C Default)
	//*(int*)0x004F20A7 = 0x0C;
	//*(int*)0x004F209D = 0x0C;
	//*(int*)0x04F29F0 = 0x004F2806;

	//*(char*)0x0043B4FB = 0x50; // LoadInterface first screen is 0x1f

	// Ignore S.DAT modifications
	//*(unsigned char*)0x00595C09 = 0xEB;

	// Change shop to use P.dat file again for tire and brakes
	//*(int*)(0x004A80D0) = (int)getTireBrakePrice;
	//*(int*)(0x004A80D4) = (int)getTireBrakePrice;
	//*(int*)(0x005312E0) = (int)getTireBrakePrice;
	//*(int*)(0x005312E4) = (int)getTireBrakePrice;
	// Base Shop Prices
	*(int*)(0x00531802) = 100; // 100;
	*(int*)(0x00531816) = 102; // 102;
	*(int*)(0x0053181E) = 118; // 104;
	*(int*)(0x00531826) = 134; // 106;
	*(int*)(0x0053182E) = 150; // 108;
	*(int*)(0x00531836) = 166; // 110;
	*(int*)(0x0053183E) = 182; // 112;
	*(int*)(0x00531846) = 150; // 115;
	*(int*)(0x0053184E) = 198; // 117;
	*(int*)(0x005317FA) = 214; // 120;

	// Number of cars?
	//*(int*)0x004A444E = 165;
	//*(int*)0x004A4AF0 = 165;
	//*(int*)0x004A4CAF = 165;
	//*(int*)0x004A80EA = 165;
	//*(int*)0x004A815A = 165;
	//*(int*)0x004C142B = 165;
	//*(int*)0x004C5521 = 165;
	//*(int*)0x004C556F = 165;
	//*(int*)0x004C568A = 165;

	// Additional Items
	// Sign limit (image in UI is in SWF so can't edit that)
	*(char*)0x004396ED = 27; // 24;
	// Item Label Sprites brought table into DLL so I can add more
	for (int i = 0; i < sizeof(itemSpriteSmallID) / sizeof(int*); i++)		*(int*)(itemSpriteSmallID[i]) = (int)(&itemSpritesSmall);
	for (int i = 0; i < sizeof(itemSpriteSmallSprite) / sizeof(int*); i++)	*(int*)(itemSpriteSmallSprite[i]) = (int)(&itemSpritesSmall) + 4;
	for (int i = 0; i < sizeof(itemSpriteSmallEnd) / sizeof(int*); i++)		*(int*)(itemSpriteSmallEnd[i]) = (int)(&itemSpritesSmall) + sizeof(itemSpritesSmall);
	for (int i = 0; i < sizeof(itemSpriteBigID) / sizeof(int*); i++)		*(int*)(itemSpriteBigID[i]) = (int)(&itemSpritesBig);
	for (int i = 0; i < sizeof(itemSpriteBigSprite) / sizeof(int*); i++)	*(int*)(itemSpriteBigSprite[i]) = (int)(&itemSpritesBig) + 4;
	for (int i = 0; i < sizeof(itemSpriteBigEnd) / sizeof(int*); i++)		*(int*)(itemSpriteBigEnd[i]) = (int)(&itemSpritesBig) + sizeof(itemSpritesBig);

	// CP Clipping on race hud fix
	*(char*)0x004D5D46 = 24;

	// Custom DirectX Stuff
	insertFunction((int)0x004C769C, directxCustom, 14, FT_CALL); // Outside Car
	insertFunction((int)0x004C8A12, directxCustom, 7, FT_CALL); // Inside Car

	// Direct Input
	//insertFunction((int)0x0040B464, adjustXAxis, 7, FT_CALL);

	// Axis Range (DIPROP_RANGE)
	*(short*)0x0040B18C = -1000; // lMin
	*(short*)0x0040B18E = 1000; // lMax

	// Axis Deadzones (DIPROP_DEADZONE)
	*(char*)0x0040B1AF = deadZonePercent; // Default 5%

	// Direct Input SetCooperativeLevel
	*(char*)0x0040AEEE = DISCL_BACKGROUND | DISCL_NONEXCLUSIVE;

	// Anti Cheat
#ifdef NDEBUGs
	// Detect cheating
	enableAntiCheat();
#endif

#pragma region Custom Packets and alterations

#pragma endregion
}
int fullScreenMode()
{
	return fullScreen ? 0 : 1;
}
int skipBootWarning()
{
	return skipWarning ? 1 : 0;
}
void setStrings()
{
	*(char**)0x0041C517 = windowTitle;
	//*(char**)0x0043B914 = versionStr; // Now in VerString Function

	for (int i = 0; i < sizeof(strings) / sizeof(STRINGENTRY); i++)
	{
		if (strings[i].ptr)
		{
			if (strings[i].mutli == TRUE)
			{
				char* currPtr = (char*)strings[i].ptr;
				while (*(int*)currPtr)
				{
					*(int*)(*(int*)currPtr) = (int)strings[i].str;
					currPtr += 4;
				}
			}
			else
				*(char**)strings[i].ptr = strings[i].str;
		}
	}

	// Item Descriptions brought table into DLL so I can add more
	for (int i = 0; i < sizeof(itemIDNumber) / sizeof(int*); i++)			*(int*)(itemIDNumber[i]) = (int)&itemDetails;
	for (int i = 0; i < sizeof(itemIDName) / sizeof(int*); i++)				*(int*)(itemIDName[i]) = (int)(&itemDetails) + 4;
	for (int i = 0; i < sizeof(itemIDDescription) / sizeof(int*); i++)		*(int*)(itemIDDescription[i]) = (int)(&itemDetails) + 8;
	for (int i = 0; i < sizeof(itemIDEnd) / sizeof(int*); i++)				*(int*)(itemIDEnd[i]) = (int)(&itemDetails) + sizeof(itemDetails);
	for (int i = 0; i < sizeof(itemIDMid) / sizeof(int*); i++)				*(int*)(itemIDMid[i]) = (int)(&itemDetails) + ((2035 * 12) + 8);
	for (int i = 0; i < sizeof(itemIDMid2) / sizeof(int*); i++)				*(int*)(itemIDMid2[i]) = (int)(&itemDetails) + (2072 * 12);

	/*
	for (int i = 0; i < sizeof(replaceStrings) / sizeof(STRINGREPLACEENTRY); i++)
	{
	if (replaceStrings[i].ptr)
	{
	memcpy(replaceStrings[i].ptr, replaceStrings[i].str, strlen(replaceStrings[i].str));
	*(char*)(replaceStrings[i].ptr + strlen(replaceStrings[i].str)) = 0;
	}
	}
	*/
}
void setResolution()
{
#pragma region Resolution
	// Disable window size check. If I do this full screen will break on unsupported resolutions by the monitor. So I'll leave it as default.
	//insertFunction(0x00412AE6, checkResolution, 286, FT_JUMP);
	//*(char*)(0x00418E77) = 2;
	//NOPSpace(0x00412AE6, 2);

	// 

	for (int i = 0; i < sizeof(resWidth) / sizeof(int); i++)
	{
		*resWidth[i] = resW;
	}
	for (int i = 0; i < sizeof(resHeight) / sizeof(int); i++)
	{
		*resHeight[i] = resH;
	}
	for (int i = 0; i < sizeof(resWidthF) / sizeof(float); i++)
	{
		*resWidthF[i] = (float)resW;
	}
	for (int i = 0; i < sizeof(resHeightF) / sizeof(float); i++)
	{
		*resHeightF[i] = (float)resH;
	}
#pragma endregion
#pragma region Positioning
	for (int i = 0; i < sizeof(centerJust) / sizeof(int); i++)
	{
		*centerJust[i] = (resW / 2) - (320 - (*centerJust[i]));
	}
	for (int i = 0; i < sizeof(centerJustV) / sizeof(int); i++)
	{
		*centerJustV[i] = (resH / 2) - (240 - (*centerJustV[i]));
	}
	for (int i = 0; i < sizeof(rightJust) / sizeof(int); i++)
	{
		*rightJust[i] = resW - (640 - *rightJust[i]);
	}
	for (int i = 0; i < sizeof(bottomJust) / sizeof(int); i++)
	{
		*bottomJust[i] = resH - (480 - *bottomJust[i]);
	}
	for (int i = 0; i < sizeof(centerJustF) / sizeof(float); i++)
	{
		*centerJustF[i] = (resW / 2) - (320 - (*centerJustF[i]));
	}
	for (int i = 0; i < sizeof(rightJustF) / sizeof(float); i++)
	{
		*rightJustF[i] = resW - (640.0f - *rightJustF[i]);
	}
	for (int i = 0; i < sizeof(bottomJustF) / sizeof(float); i++)
	{
		*bottomJustF[i] = resH - (480.0f - *bottomJustF[i]);
	}
	for (int i = 0; i < sizeof(repositionAddr) / sizeof(int); i++)
	{
		insertFunction((int)repositionAddr[i], positionUIElement, 5, FT_CALL);
	}
	insertFunction(0x0045F6C8, positionUIElement3, 5, FT_CALL);

	// Battle strings
	insertFunction(0x004DE74D, placeStringLeftAlign, 5, FT_CALL);
	insertFunction(0x004DE79B, placeStringLeftAlign, 5, FT_CALL);
	insertFunction(0x004DE7E9, placeStringRightAlign, 5, FT_CALL);
	insertFunction(0x004DE839, placeStringRightAlign, 5, FT_CALL);


	//for (int i = 0; i < sizeof(repositionIntAddr) / sizeof(int); i++)
	//{
	//	insertFunction((int)repositionIntAddr[i], logPositionUIElement, 5, FT_CALL);
	//}
	//for (int i = 0; i < sizeof(repositionIntAddr) / sizeof(int); i++)
	//{
	//	insertFunction((int)repositionIntAddr[i], positionUIElement2, 5, FT_CALL);
	//}
#pragma endregion
#pragma region Aspect Ratio
	// Course Aspect
	*(float*)0x005F404C = (float)resW / (float)resH;

	// Shops and UI Aspects - Looks bad when UI is stretched so will leave it scretched in shops.
	//*(float*)0x004A4232 = (float)resW / (float)resH;
	//*(float*)0x004E100F = (float)resW / (float)resH;
	//*(float*)0x00501928 = (float)resW / (float)resH;
	//*(float*)0x0050195a = (float)resW / (float)resH;
#pragma endregion
#pragma region Scaling Patches
	//insertFunction((int)0x00508470, scaleUIElement, 0x7F, FT_JUMP);
	//*(float**)0x00512332 = &floattest1;
	//*(float**)0x0051236F = &floattest2;
	UIdividerX = (640.0f / resW) * 20.0f;
	UIdividerY = (480.0f / resH) * 20.0f;
	UIscaleX = (float)((double)(0.05f / 640.0f) * resW);
	UIscaleY = (float)((double)(0.05f / 480.0f) * resH);
	itemUseDialogX = (resW / 2) - (320 - itemUseDialogX);
	itemUseDialogY = (resH / 2) - (240 - itemUseDialogY);

	*(float**)0x00416DC0 = &UIdividerX;
	*(float**)0x00416DCE = &UIdividerY;

	// Shadows in Garage effected
	*(float**)0x004587D3 = &UIdividerX;
	*(float**)0x004587EE = &UIdividerY;

	// UI Selection Position effected
	*(float**)0x0051C9B2 = &UIdividerX;
	*(float**)0x0051C9D3 = &UIdividerY;

	*(float**)0x005084AA = &UIscaleX;
	*(float**)0x005084C2 = &UIscaleY;

	*(float**)0x0050977F = &UIscaleX;
	*(float**)0x0050978E = &UIscaleY;

	*(float**)0x00511A1F = &UIscaleX;
	*(float**)0x00511A35 = &UIscaleY;

	*(float**)0x00511A4B = &UIscaleX;
	*(float**)0x00511A61 = &UIscaleY;

	// UI affected
	*(float**)0x00512332 = &UIscaleX;
	*(float**)0x0051236F = &UIscaleY;

	*(float**)0x0051249F = &UIscaleX;
	*(float**)0x005124D6 = &UIscaleY;

	*(float**)0x00512A3B = &UIscaleX;
	*(float**)0x00512A64 = &UIscaleY;

	*(float**)0x005133D5 = &UIscaleX;
	*(float**)0x005133E8 = &UIscaleY;

	*(float**)0x005133FB = &UIscaleX;
	*(float**)0x00513407 = &UIscaleY;

	//*(float**)0x00515594 = &UIscaleX;
	*(float**)0x005155A6 = &UIscaleY;
	*(float**)0x005155D6 = &UIscaleX;

	//*(float**)0x00515753 = &UIscaleX;
	*(float**)0x0051576C = &UIscaleY;
	*(float**)0x0051577A = &UIscaleX;

	// Input fields affected
	*(float**)0x00516035 = &UIscaleY;
	*(float**)0x0051604E = &UIscaleX;

	// UI interaction
	insertFunction(0x00512BE4, adjustUI, 5, FT_CALL);

	// Set dialog positions and such
	//insertFunction(0x0045C7E0, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0045C7E5, setItemUsePosition, 14, FT_CALL);
	//insertFunction(0x0045FFE4, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x00466124, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0046AA84, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0046D794, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x004833E4, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x00483BD4, setTexturePositions, 5, FT_CALL);
	//insertFunction(0x0048DDEE, setTexturePositions, 5, FT_CALL);

	// Custom draw string

	for (int i = 0; i < sizeof(drawStringAddr) / sizeof(int); i++)
	{
		insertFunction((int)drawStringAddr[i], drawString, 5, FT_CALL);
	}

	// Mirror
	*(int*)0x004E185B = (int)(((float)(*(int*)0x004E185B) / 480.0f) * resH); // Width
	*(int*)0x004E1862 = (int)(((float)(*(int*)0x004E1862) / 480.0f) * resH); // Height

	*(int*)0x004E184D = (resW / 2) - (*(int*)0x004E185B / 2); // X Position
															  //*(int*)0x004E1854; // Y Position

															  // Mirror Frame
															  //*(float*)0x004C1F26; // Top Height
	*(float*)0x004C1F2B = (float)(*(int*)0x004E185B) + 4.0f; // Top Width
															 //*(float*)0x004C1F30; // Top Y
	*(float*)0x004C1F35 = (float)(*(int*)0x004E184D) - 2.0f; // Top X
															 //*(float*)0x004C1F47; // Bottom Height
	*(float*)0x004C1F4C = (float)(*(int*)0x004E185B) + 4.0f; // Bottom Width
	*(float*)0x004C1F51 = *(float*)0x004C1F30 + ((float)(*(int*)0x004E1862) + 2.0f); // Bottom Y
	*(float*)0x004C1F56 = (float)(*(int*)0x004E184D) - 2.0f; // Bottom X
	*(float*)0x004C1F68 = (float)(*(int*)0x004E1862) + 2.0f; // Left Height
															 //*(float*)0x004C1F6D; // Left Width
															 //*(float*)0x004C1F72; // Left Y
	*(float*)0x004C1F77 = (float)(*(int*)0x004E184D) - 2.0f; // Left X
	*(float*)0x004C1F89 = (float)(*(int*)0x004E1862) + 2.0f; // Right Height
															 //*(float*)0x004C1F8E; // Right Width
															 //*(float*)0x004C1F93; // Right Y
	*(float*)0x004C1F98 = (float)(*(int*)0x004E184D) + (float)(*(int*)0x004E185B); // Right X

#pragma endregion
}
void fixResolutionChoice()
{
	// If an unsupported resolution is set use the closest supported resolution
	int supportedResolutions[2][30] = { 0 };
	int lastResolution[2] = { 0 };
	DEVMODE dm = { 0 };
	dm.dmSize = sizeof(dm);
	int settingCount = 0;

	// Get supported resolutions
	for (int i = 0; EnumDisplaySettings(NULL, i, &dm) != 0; i++)
	{
		if (settingCount == 30) break;
		if (lastResolution[0] != dm.dmPelsWidth && lastResolution[1] != dm.dmPelsHeight)
		{
			supportedResolutions[0][settingCount] = dm.dmPelsWidth;
			supportedResolutions[1][settingCount] = dm.dmPelsHeight;
			settingCount++;
		}
		lastResolution[0] = dm.dmPelsWidth;
		lastResolution[1] = dm.dmPelsHeight;
	}

	// Check if set resolution matches a supported one found. If so return
	for (int i = 0; i < settingCount; i++)
	{
		if (supportedResolutions[0][i] == resW && supportedResolutions[1][i] == resH)
			return;
	}

	// Resolution set isn't supported so use the closest supported resolution
	for (int i = 0; i < settingCount; i++)
	{
		if (supportedResolutions[0][i] > resW && i == 0)
		{
			resW = supportedResolutions[0][i];
			resH = supportedResolutions[1][i];
			break;
		}
		else if (supportedResolutions[0][i] > resW)
		{
			resW = supportedResolutions[0][i - 1];
			resH = supportedResolutions[1][i - 1];
			break;
		}
		else  if (i == settingCount - 1)
		{
			resW = supportedResolutions[0][i];
			resH = supportedResolutions[1][i];
			break;
		}
	}
}
void __cdecl windowMonitorThread(void* parg)
{
	bool running = true;
	while (running)
	{
		if ((*(void**)(0x006EAAE0)) && !dx)
		{
			dx = (LPDIRECT3DDEVICE8)(*(void**)(0x006EAAE0));
		}
		if (closeCheck)
		{
			if (IsWindowVisible(*hwnd) == false) running = false;
		}
		Sleep(100);
	}
	_Exit(0);
}
void readRegistry()
{
	DWORD value;
	DWORD BufferSize = 4;
	HKEY hKey;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Genki\\SBOL"), 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
	{
		BufferSize = sizeof(DWORD);
		if (RegQueryValueEx(hKey, TEXT("RES_WIDTH"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			if ((resW = value) < 640)
				resW = 640;
		}
		else
		{
			resW = 640;
			RegSetValueEx(hKey, TEXT("RES_WIDTH"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resW), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueEx(hKey, TEXT("RES_HEIGHT"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			if ((resH = value) < 480)
				resH = 480;
		}
		else
		{
			resH = 480;
			RegSetValueEx(hKey, TEXT("RES_HEIGHT"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resH), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueEx(hKey, TEXT("FULLSCREEN"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			fullScreen = value ? 1 : 0;
		}
		else
		{
			fullScreen = 0;
			RegSetValueEx(hKey, TEXT("FULLSCREEN"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&fullScreen), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueEx(hKey, TEXT("SKIPWARNING"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			skipWarning = value ? 1 : 0;
		}
		else
		{
			skipWarning = 0;
			RegSetValueEx(hKey, TEXT("SKIPWARNING"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&skipWarning), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueEx(hKey, TEXT("SHUFFLEBGM"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			shuffleBGM = value ? 1 : 0;
		}
		else
		{
			shuffleBGM = 0;
			RegSetValueEx(hKey, TEXT("SHUFFLEBGM"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&shuffleBGM), BufferSize);
		}

		BufferSize = sizeof(DWORD);
		if (RegQueryValueEx(hKey, TEXT("AXIS_DEADZONE"), NULL, NULL, reinterpret_cast<LPBYTE>(&value), &BufferSize) == ERROR_SUCCESS)
		{
			deadZonePercent = static_cast<char>(value);
			if (deadZonePercent < 0 || deadZonePercent > 100)
			{
				deadZonePercent = 5;
				RegSetValueEx(hKey, TEXT("AXIS_DEADZONE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&deadZonePercent), BufferSize);
			}
		}
		else
		{
			deadZonePercent = 5;
			RegSetValueEx(hKey, TEXT("AXIS_DEADZONE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&deadZonePercent), BufferSize);
		}
	}
	else
	{
		resW = 640;
		resH = 480;
		fullScreen = 0;
		skipWarning = 0;
		shuffleBGM = 0;
		deadZonePercent = 5;
		if (RegCreateKeyEx(HKEY_CURRENT_USER, TEXT("Software\\Genki\\SBOL"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL) == ERROR_SUCCESS)
		{
			BufferSize = sizeof(DWORD);
			RegSetValueEx(hKey, TEXT("RES_WIDTH"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resW), BufferSize);
			RegSetValueEx(hKey, TEXT("RES_HEIGHT"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&resH), BufferSize);
			RegSetValueEx(hKey, TEXT("FULLSCREEN"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&fullScreen), BufferSize);
			RegSetValueEx(hKey, TEXT("SKIPWARNING"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&fullScreen), BufferSize);
			RegSetValueEx(hKey, TEXT("SHUFFLEBGM"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&shuffleBGM), BufferSize);
			RegSetValueEx(hKey, TEXT("AXIS_DEADZONE"), 0, REG_DWORD, reinterpret_cast<LPBYTE>(&deadZonePercent), BufferSize);
		}
	}

	RegCloseKey(hKey);
}
void Log(char type, char* in)
{
	char* text = (char*)calloc(1, strlen(in) + 2);
	if (text == nullptr) return;
	char logbuf[FILENAME_MAX];
	char* LOGFILES[]{
		"type0_",
		"type1_"
	};

	SYSTEMTIME rawtime;
	GetLocalTime(&rawtime);
	strncpy(text, in, strlen(in) + 2);
	type %= 2;

	snprintf(logbuf, sizeof(logbuf), "log\\%s%02u%02u%04u.log", LOGFILES[type], rawtime.wMonth, rawtime.wDay, rawtime.wYear);
	std::fstream logFile(logbuf, std::ios::app | std::ios::ate);
	if (logFile.is_open())
	{
		logFile << text;
		logFile.close();
	}
	free(text);
}
int debugLog(char *buffer, size_t count, const char *format, va_list argptr)
{
	char* compare = nullptr;
	if (strlen(buffer) != 0)
	{
		compare = (char*)calloc(1, strlen(buffer) + 1);
		if (compare == nullptr) return 0;
		strncpy(compare, buffer, strlen(buffer) + 1);
	}
	int res = vsnprintf(buffer, count, format, argptr);
	if (compare != nullptr)
	{
		if (strcmp(compare, buffer) != 0)
		{
			if (buffer[strlen(buffer) - 1] != 0x0A) buffer[strlen(buffer)] = 0x0A;
			Log(1, buffer);
		}
	}
	if (compare != nullptr) free(compare);
	return res;
}
int debugIt(const char *format, ...)
{
	va_list vars;
	va_start(vars, format);
	//return debugLog((char*)0x6F7BCC, 0x400, format, vars);
	return debugLog(&logItBuf[0], 0x400, format, vars);
	va_end(vars);
}
int VerString(char* str, const char* format, ...)
{
	return sprintf(str, versionStr, clientVer[0], clientVer[1], clientVer[2], clientVer[3]);
}
