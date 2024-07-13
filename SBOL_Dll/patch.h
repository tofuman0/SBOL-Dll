#pragma once
#ifndef PATCH_HEADER
#define PATCH_HEADER
#include <Windows.h>
#include <process.h>
#include <dinput.h>
#include <Psapi.h>
#include <fstream>
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
#endif