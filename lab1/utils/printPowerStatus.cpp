#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintSystemPowerStatus() {
	SYSTEM_POWER_STATUS sps;
	GetSystemPowerStatus(&sps);
	std::cout << "AC Line Status: " << (int)sps.ACLineStatus << std::endl;
}