#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

void PrintVirtualMemoryMap() {
	HANDLE process = GetCurrentProcess();
	MEMORY_BASIC_INFORMATION info;
	unsigned char *addr = nullptr;

	cout << "Virtual Memory Map:" << endl;
	while (VirtualQueryEx(process, addr, &info, sizeof(info)) == sizeof(info)) {
		cout << "Base Address: " << info.BaseAddress << ", ";
		cout << "Region Size: " << info.RegionSize / 1024 << " KB, ";
		cout << "State: " << ((info.State == MEM_COMMIT) ? "Committed" : (info.State == MEM_RESERVE) ? "Reserved" : "Free") << endl;
		addr += info.RegionSize;
	}
}