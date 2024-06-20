#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

using namespace std;

void PrintCountProcessesAndThreads() {
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (Process32First(hSnapshot, &pe32)) {
		int processCount = 0;
		do {
			processCount++;
		} while (Process32Next(hSnapshot, &pe32));
		cout << "Total processes: " << processCount << endl;
	}
	CloseHandle(hSnapshot);

	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	THREADENTRY32 te32;
	te32.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(hSnapshot, &te32)) {
		int threadCount = 0;
		do {
			threadCount++;
		} while (Thread32Next(hSnapshot, &te32));
		cout << "Total threads: " << threadCount << endl;
	}
	CloseHandle(hSnapshot);
}
