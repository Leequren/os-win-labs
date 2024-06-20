#define _WIN32_WINNT 0x0501

#include <windows.h>
#include <iostream>

using namespace std;

void PrintCpuTimes() {
	FILETIME idleTime, kernelTime, userTime;
	if (GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
		ULARGE_INTEGER idle, kernel, user;
		idle.LowPart = idleTime.dwLowDateTime;
		idle.HighPart = idleTime.dwHighDateTime;
		kernel.LowPart = kernelTime.dwLowDateTime;
		kernel.HighPart = kernelTime.dwHighDateTime;
		user.LowPart = userTime.dwLowDateTime;
		user.HighPart = userTime.dwHighDateTime;

		ULONGLONG kernelAndUser = kernel.QuadPart + user.QuadPart;
		ULONGLONG total = kernelAndUser + idle.QuadPart;

		cout << "User Time (%): " << (user.QuadPart * 100.0 / total) << endl;
		cout << "Privileged Time (%): " << ((kernel.QuadPart - idle.QuadPart) * 100.0 / total) << endl;
		cout << "Idle Time (%): " << (idle.QuadPart * 100.0 / total) << endl;
	} else {
		cerr << "Failed to get system times." << endl;
	}
}
