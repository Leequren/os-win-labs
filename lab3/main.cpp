#include <windows.h>
#include <iostream>
#include <tchar.h>
#include <lmcons.h>
#include "utils/utils.h"

using namespace std;

int main() {
	PrintMemoryStatus();
	PrintVirtualMemoryMap();

	return 0;
}
