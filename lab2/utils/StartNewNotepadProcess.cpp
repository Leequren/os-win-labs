#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

using namespace std;

void StartNewNotepadProcess() {
	STARTUPINFO si = {};
	PROCESS_INFORMATION pi = {};
	si.cb = sizeof(si);

	if (!CreateProcess(TEXT("C:\\Windows\\System32\\notepad.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		cerr << "Process creation failed: " << GetLastError() << endl;
	}
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}