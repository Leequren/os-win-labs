#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

void PrintMemoryStatus() {
	MEMORYSTATUS stat;
	GlobalMemoryStatus(&stat);

	cout << "Memory in Use: " << stat.dwMemoryLoad << "%" << endl;
	cout << "Total Physical Memory (MB): " << stat.dwTotalPhys / 1024 / 1024 << endl;
	cout << "Available Physical Memory (MB): " << stat.dwAvailPhys / 1024 / 1024 << endl;
	cout << "Total Virtual Memory (MB): " << stat.dwTotalVirtual / 1024 / 1024 << endl;
	cout << "Available Virtual Memory (MB): " << stat.dwAvailVirtual / 1024 / 1024 << endl;
}

