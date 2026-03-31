#pragma once
#ifndef PATCH_HEADER
#define PATCH_HEADER
#include <Windows.h>
#include <process.h>
#include <dinput.h>
#include <Psapi.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <locale>
#include <clocale>
#include <mbctype.h>
#include <debugapi.h>
#include "asm.h"
#include "bgm.h"
#include "dx.h"
#include "DXFont.h"
#include "OggPlayer.h"

void patchClient();
int fullScreenMode();
int skipBootWarning();
void setStrings();
void setDrawDistance();
void setResolution();
void fixResolutionChoice();
void windowMonitorThread(void* parg);
void readRegistry();
void Log(char type, char* in);
int debugLog(char *buffer, size_t count, const char *format, va_list argptr);
int debugIt(const char *format, ...);
int VerString(char* str, const char* format, ...);
void ForceShiftJIS();
int __stdcall MultiByteToWideCharHook(UINT CodePage, DWORD dwFlags, LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar);
constexpr void* MultiByteToWideCharHook_Ptr = (void*)(&MultiByteToWideCharHook);
LCID __stdcall GetUserDefaultLCIDHook();
constexpr void* GetUserDefaultLCIDHook_Ptr = (void*)(&GetUserDefaultLCIDHook);
int __stdcall GetLocaleInfoAHook(LCID Locale, LCTYPE LCType, LPSTR lpLCData, int cchData);
constexpr void* GetLocaleInfoAHook_Ptr = (void*)(&GetLocaleInfoAHook);
int __stdcall GetLocaleInfoWHook(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData);
constexpr void* GetLocaleInfoWHook_Ptr = (void*)(&GetLocaleInfoWHook);
UINT __stdcall GetACPHook();
constexpr void* GetACPHook_Ptr = (void*)(&GetACPHook);
BOOL __stdcall GetCPInfoHook(UINT CodePage, LPCPINFO lpCPInfo);
constexpr void* GetCPInfoHook_Ptr = (void*)(&GetCPInfoHook);
HFONT __stdcall CreateFontAHook(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, DWORD bItalic, DWORD bUnderline, DWORD bStrikeOut, DWORD iCharSet, DWORD iOutPrecision, DWORD iClipPrecision, DWORD iQuality, DWORD iPitchAndFamily, LPCSTR pszFaceName);
constexpr void* CreateFontAHook_Ptr = (void*)(&CreateFontAHook);
HFONT __stdcall CreateFontIndirectAHook(LOGFONTA* lplf);
constexpr void* CreateFontIndirectAHook_Ptr = (void*)(&CreateFontIndirectAHook);
BOOL __stdcall GetTextMetricsAHook(HDC hdc, LPTEXTMETRICA lptm);
constexpr void* GetTextMetricsAHook_Ptr = (void*)(&GetTextMetricsAHook);
void __stdcall HandleMessages(LPMSG lpMsg);
constexpr void* HandleMessageHook_Ptr = (void*)(&HandleMessages);
BOOL __stdcall TextOutAHook(HDC hdc, int x, int y, LPCSTR lpString, int c);
constexpr void* TextOutAHook_Ptr = (void*)(&TextOutAHook);
#endif