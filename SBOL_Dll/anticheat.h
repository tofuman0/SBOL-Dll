#pragma once
#include <Windows.h>
#include <process.h>
#include <Psapi.h>
#include "AntiRE.h"

#define WINDOW_BUFFER_SIZE		1024
#define MAX_PROCESSES_TO_SCAN	4096

int _HASH1, _HASH2, _HASH3, _HASH4;
DWORD *processBuffer;
wchar_t *processNameBuffer, *WindowNameBuffer, *WindowClassBuffer, *processTitleBuffer;
const wchar_t* banned_windows[] {
	//TEXT("cheat engine"), TEXT("window"),
	//TEXT("wpe pro"), NULL,
	//TEXT("winsockspy.send"), NULL,
	//TEXT("winsockspy.client"), NULL,
	//NULL, TEXT("winsockspy.sendclass"),
	//NULL, TEXT("winsockspy.clientclass"),
	//TEXT("redox packet editor"), NULL,
	//TEXT("filter editor - rpe"), NULL,
	//TEXT("ollydbg"), TEXT("ollydbg"),
	//TEXT("x32dbg"), TEXT("qwidget"),
	//TEXT("x64dbg"), TEXT("qwidget"),
	NULL, NULL
};
const wchar_t* banned_processes[]{
	//TEXT("cheatengine"),
	//TEXT("rpe.exe"),
	//TEXT("x32dbg"),
	//TEXT("x64dbg"),
	//TEXT("wpepro"),
	NULL
};

int getHash(int offset, int size);
void hashThread(void* parg);
void cheatThread(void* parg);
void processThread(void* parg);
BOOL CALLBACK enumWindowsProc(__in  HWND hWnd, __in  LPARAM lParam);
BOOL GetWindowList();
BOOL GetProcessList();
void enableAntiCheat();
