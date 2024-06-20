#include <windows.h>
#include <iostream>
#include <vector>

CRITICAL_SECTION CriticalSection;
HANDLE Mutex;
HANDLE Event;

// Задача с использованием критических секций
DWORD WINAPI UsePrinter(LPVOID lpParam) {
	EnterCriticalSection(&CriticalSection);
	std::cout << "Кассир " << GetCurrentThreadId() << " печатает чек." << std::endl;
	Sleep(1000); // Имитация занятости
	LeaveCriticalSection(&CriticalSection);
	return 0;
}

// Задача с использованием мьютексов
DWORD WINAPI AccessAccount(LPVOID lpParam) {
	WaitForSingleObject(Mutex, INFINITE);
	std::cout << "Банкомат " << GetCurrentThreadId() << " осуществляет транзакцию." << std::endl;
	Sleep(1000); // Имитация транзакции
	ReleaseMutex(Mutex);
	return 0;
}

// Задача с использованием событий
DWORD WINAPI FireAlarm(LPVOID lpParam) {
	std::cout << "Датчик " << GetCurrentThreadId() << " ожидает дым." << std::endl;
	WaitForSingleObject(Event, INFINITE);
	std::cout << "Датчик " << GetCurrentThreadId() << " обнаружил дым и активировал сигнализацию!" << std::endl;
	return 0;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
	InitializeCriticalSection(&CriticalSection);
	Mutex = CreateMutex(NULL, FALSE, NULL);
	Event = CreateEvent(NULL, TRUE, FALSE, NULL);

	std::vector<HANDLE> threads;
	threads.push_back(CreateThread(NULL, 0, UsePrinter, NULL, 0, NULL));
	threads.push_back(CreateThread(NULL, 0, AccessAccount, NULL, 0, NULL));
	threads.push_back(CreateThread(NULL, 0, FireAlarm, NULL, 0, NULL));

	Sleep(3000); // Подождем, пока потоки выполнят свои задачи
	SetEvent(Event); // Активация события дым

	for (HANDLE thread : threads) {
		WaitForSingleObject(thread, INFINITE);
		CloseHandle(thread);
	}

	DeleteCriticalSection(&CriticalSection);
	CloseHandle(Mutex);
	CloseHandle(Event);

	return 0;
}
