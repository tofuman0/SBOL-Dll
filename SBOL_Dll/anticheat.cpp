#include "anticheat.h"

int getHash(int offset, int size)
{
	int tempHash = 0;
	int* moo = nullptr;
	for (int i = 0; i < size / 4; i++)
	{
		moo = (int*)(offset + (i * 4));
		tempHash ^= *(int*)(offset + (i * 4));
	}
	return tempHash;
}
void __cdecl hashThread(void* parg)
{
	for (;;)
	{
		Sleep(1000);
		if (getHash(0x00401000, 0x1B3BC0) != _HASH1)
			exit(100);
		Sleep(1000);
		if (getHash(0x005B5013, 0x71EFA) != _HASH2)
			exit(101);
	}
}
void __cdecl cheatThread(void* parg)
{
	for (;;)
	{
		Sleep(100);
		if (CanOpenCsrss() == true) exit(200);
		Sleep(100);
		if (DebugObjectCheck() == true) exit(201);
		Sleep(100);
		if (Int2DCheck() == true) exit(202);
		Sleep(100);
		if (IsDbgPresentPrefixCheck() == true) exit(203);
		Sleep(100);
		if (ObjectListCheck() == true) exit(204);
	}
}
void __cdecl processThread(void* parg)
{
	for (;;)
	{
		Sleep(1000);
		if (GetProcessList() == TRUE) exit(300);
		Sleep(1000);
		if (GetWindowList() == TRUE) exit(301);
	}
}
BOOL CALLBACK enumWindowsProc(__in  HWND hWnd, __in  LPARAM lParam) {
	int i;
	int match = 0;

	GetWindowText(hWnd, WindowNameBuffer, WINDOW_BUFFER_SIZE);
	GetClassName(hWnd, WindowClassBuffer, WINDOW_BUFFER_SIZE);

	for (i = 0; (unsigned)i < wcslen(WindowNameBuffer); i++)
		WindowNameBuffer[i] = towlower(WindowNameBuffer[i]);

	for (i = 0; (unsigned)i < wcslen(WindowClassBuffer); i++)
		WindowClassBuffer[i] = towlower(WindowClassBuffer[i]);

	i = 0;

	while (1)
	{
		if ((banned_windows[i] == NULL) && (banned_windows[i + 1] == NULL))
			break;

		match = 1;

		if (banned_windows[i] != NULL)
		{
			if (wcsstr(WindowNameBuffer, banned_windows[i]) == NULL)
				match = 0;
		}

		if (banned_windows[i + 1] != NULL)
		{
			if (wcsstr(WindowClassBuffer, banned_windows[i + 1]) == NULL)
				match = 0;
		}

		if (match)
			break;

		i += 2;
	}
	if (match)
	{
		return TRUE;
	}
	return FALSE;
}
BOOL GetWindowList()
{
	return EnumWindows(enumWindowsProc, NULL);
}
BOOL GetProcessList()
{
	DWORD numProcesses;
	HANDLE hProcess;
	int match = 0, i;

	if (!EnumProcesses(processBuffer, MAX_PROCESSES_TO_SCAN * sizeof(DWORD), &numProcesses))
	{
		return FALSE; // FAILED
	}

	numProcesses /= sizeof(DWORD);


	while (numProcesses)
	{
		numProcesses--;
		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |
			PROCESS_VM_READ,
			FALSE, processBuffer[numProcesses]);
		if (hProcess != NULL)
		{
			GetProcessImageFileName(hProcess, processNameBuffer, MAX_PATH);

			i = 0;

			while (processNameBuffer[i])
			{
				processNameBuffer[i] = towlower(processNameBuffer[i]);
				i++;
			}

			i = 0;

			while (banned_processes[i] != NULL)
			{
				if (wcsstr(processNameBuffer, banned_processes[i]))
				{
					match = 1;
					break;
				}
				i++;
			}
		}
		CloseHandle(hProcess);
		if (match)
			break;
	}
	if (match)
	{
		return TRUE;
	}
	return FALSE;
}
void enableAntiCheat()
{
	WindowNameBuffer = (wchar_t*)malloc(WINDOW_BUFFER_SIZE * 4L);
	WindowClassBuffer = (wchar_t*)malloc(WINDOW_BUFFER_SIZE * 4L);
	processBuffer = (DWORD*)malloc(MAX_PROCESSES_TO_SCAN * sizeof(DWORD) * 2);
	processNameBuffer = (wchar_t*)malloc(MAX_PATH * 4L);

	_beginthread(cheatThread, 0, NULL);
	_beginthread(processThread, 0, NULL);
	_HASH1 = getHash(0x00401000, 0x1B3BC0);
	_HASH2 = getHash(0x005B5013, 0x71EFA);
	_HASH3 = 0;
	_HASH4 = 0;
	_beginthread(hashThread, 0, NULL);
}