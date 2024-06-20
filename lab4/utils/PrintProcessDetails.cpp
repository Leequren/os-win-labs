#define _WIN32_WINNT 0x0501

#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

using namespace std;

void PrintProcessDetails() {
	// Получение идентификатора текущего процесса
	DWORD processID = GetCurrentProcessId();
	cout << "Current Process ID: " << processID << endl;

	// Получение псевдодескриптора текущего процесса
	HANDLE pseudoHandle = GetCurrentProcess();
	cout << "Pseudo Handle: " << pseudoHandle << endl;

	// Дублирование псевдодескриптора
	HANDLE trueHandle;
	BOOL duplicateResult = DuplicateHandle(GetCurrentProcess(), pseudoHandle, GetCurrentProcess(),
	                                       &trueHandle, 0, FALSE, DUPLICATE_SAME_ACCESS);
	if (duplicateResult) {
		cout << "Duplicate Handle: " << trueHandle << endl;
	} else {
		cout << "Failed to duplicate handle." << endl;
	}

	// Получение дескриптора с использованием OpenProcess
	HANDLE openHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if (openHandle) {
		cout << "Opened Process Handle: " << openHandle << endl;
	} else {
		cout << "Failed to open process." << endl;
	}

	// Закрытие дескрипторов
	CloseHandle(trueHandle);
	CloseHandle(openHandle);

	// Перечисление всех процессов в системе
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnapshot, &pe32)) {
			cout << "List of processes:" << endl;
			do {
				wcout   << "Process ID: " << pe32.th32ProcessID << ", Process Name: "
				        << pe32.szExeFile << endl;
			} while (Process32Next(hSnapshot, &pe32));
		} else {
			wcout << "Failed to retrieve processes." << endl;
		}
		CloseHandle(hSnapshot);
	} else {
		wcout << "Failed to create snapshot." << endl;
	}
}

void PrintModuleInfo(HANDLE processHandle) {
	MODULEENTRY32 me32;
	me32.dwSize = sizeof(MODULEENTRY32);
	HANDLE hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, GetProcessId(processHandle));
	if (hModuleSnap == INVALID_HANDLE_VALUE) {
		cout << "Failed to take snapshot of modules." << endl;
		return;
	}

	if (Module32First(hModuleSnap, &me32)) {
		do {
			wcout << L"Module Name: " << me32.szModule << L"\n";
			wcout << L"Executable Path: " << me32.szExePath << L"\n\n";
		} while (Module32Next(hModuleSnap, &me32));
	} else {
		cout << "Failed to retrieve module information." << endl;
	}
	CloseHandle(hModuleSnap);
}
