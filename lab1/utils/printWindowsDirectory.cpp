#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintWindowsDirectory() {
	TCHAR windowsPath[MAX_PATH];
	GetWindowsDirectory(windowsPath, MAX_PATH);
	std::wcout << L"Windows Directory: " << windowsPath << std::endl;
}
