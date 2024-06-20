#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintSystemDirectory() {
	TCHAR systemPath[MAX_PATH];
	GetSystemDirectory(systemPath, MAX_PATH);
	std::wcout << L"System Directory: " << systemPath << std::endl;
}

void PrintWindowsVersion() {
	OSVERSIONINFO osvi;
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&osvi);
	std::wcout << L"Windows Version: " << osvi.dwMajorVersion << L"." << osvi.dwMinorVersion << std::endl;
}