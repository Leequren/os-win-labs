#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintSystemTime() {
	SYSTEMTIME st;
	GetSystemTime(&st);
	std::cout << "System Time: " << st.wHour << ":" << st.wMinute << std::endl;
}

void PrintSystemTimeAsFileTime() {
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);
	std::cout << "System Time as File Time: " << ft.dwLowDateTime << std::endl;
}
