#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintUserName() {
	TCHAR userName[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName(userName, &size);
	std::wcout << L"User Name: " << userName << std::endl;
}