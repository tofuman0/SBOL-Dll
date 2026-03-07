#pragma once
#ifndef PATCH_HEADER
#define PATCH_HEADER
#include <Windows.h>
#include <process.h>
#include <dinput.h>
#include <Psapi.h>
#include <fstream>
#include <locale>
#include <clocale>
#include <mbctype.h>
#include "asm.h"
#include "bgm.h"
#include "dx.h"
#include "DXFont.h"
#include "OggPlayer.h"

void patchClient();
int fullScreenMode();
int skipBootWarning();
void setStrings();
void setResolution();
void fixResolutionChoice();
void windowMonitorThread(void* parg);
void readRegistry();
void Log(char type, char* in);
int debugLog(char *buffer, size_t count, const char *format, va_list argptr);
int debugIt(const char *format, ...);
int VerString(char* str, const char* format, ...);
void ForceShiftJIS();
int __stdcall MultiByteToWideCharShiftJIS(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
constexpr void* MultiByteToWideCharShiftJIS_Ptr = (void*)(&MultiByteToWideCharShiftJIS);
LCID GetUserDefaultLCIDShiftJIS();
constexpr void* GetUserDefaultLCIDShiftJIS_Ptr = (void*)(&GetUserDefaultLCIDShiftJIS);
int GetLocaleInfoAShiftJIS(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData);
constexpr void* GetLocaleInfoAShiftJIS_Ptr = (void*)(&GetLocaleInfoAShiftJIS);
int GetLocaleInfoWShiftJIS(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData);
constexpr void* GetLocaleInfoWShiftJIS_Ptr = (void*)(&GetLocaleInfoWShiftJIS);
UINT GetACPShiftJIS();
constexpr void* GetACPShiftJIS_Ptr = (void*)(&GetACPShiftJIS);
BOOL GetCPInfoShiftJIS(UINT CodePage, LPCPINFO lpCPInfo);
constexpr void* GetCPInfoShiftJIS_Ptr = (void*)(&GetCPInfoShiftJIS);
HFONT CreateFontAShiftJIS(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
constexpr void* CreateFontAShiftJIS_Ptr = (void*)(&CreateFontAShiftJIS);
#endif