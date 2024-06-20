#include "utils.h"
#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>

void ChangeConsoleTextColor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	std::cout << "This text is blue now." << std::endl;
}