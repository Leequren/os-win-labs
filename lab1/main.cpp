#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>
#include "utils/utils.h"

using namespace std;

int main() {
	PrintComputerName();
	PrintUserName();
	PrintSystemDirectory();
	PrintWindowsDirectory();
	PrintWindowsVersion();
	PrintScreenMetrics();
	PrintSystemPowerStatus();
	PrintSystemTime();
	PrintSystemTimeAsFileTime();
	ChangeConsoleTextColor();

	return 0;
}
