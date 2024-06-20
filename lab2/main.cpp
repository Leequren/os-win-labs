#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include "utils/utils.h"

using namespace std;

int main() {
	PrintCountProcessesAndThreads();
	StartNewNotepadProcess();
	PrintCpuTimes();

	return 0;
}
