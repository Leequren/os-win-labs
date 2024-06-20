#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void PrintScreenMetrics() {
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	std::cout << "Screen Height: " << screenHeight << std::endl;
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	std::cout << "Screen Width: " << screenWidth << std::endl;
}