#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include "utils/utils.h"

using namespace std;

int main() {

	DWORD processID = GetCurrentProcessId();
	cout << "Current Process ID: " << processID << endl;

	HANDLE pseudoHandle = GetCurrentProcess();
	cout << "Pseudo Handle: " << pseudoHandle << endl;

	HANDLE trueHandle;
	if (!DuplicateHandle(GetCurrentProcess(), pseudoHandle, GetCurrentProcess(), &trueHandle, 0, FALSE, DUPLICATE_SAME_ACCESS)) {
		cout << "Failed to duplicate handle." << endl;
	} else {
		cout << "Duplicate Handle: " << trueHandle << endl;
	}

	HANDLE openHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if (openHandle) {
		cout << "Opened Process Handle: " << openHandle << endl;
		PrintModuleInfo(openHandle);
	} else {
		cout << "Failed to open process." << endl;
	}

	CloseHandle(trueHandle);
	CloseHandle(openHandle);


	PrintProcessDetails();
	return 0;
}
