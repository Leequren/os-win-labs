#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintComputerName() {
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	GetComputerName(computerName, &size);
	std::wcout << L"Computer Name: " << computerName << std::endl;
}
