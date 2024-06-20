#include <windows.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <string>

using namespace std;

mutex cout_mutex;
queue<wstring> message_queue;

void printMessages() {
	while (!message_queue.empty()) {
		wcout << message_queue.front() << endl;
		message_queue.pop();
	}
}

void logMessage(const wstring& message) {
	lock_guard<mutex> lock(cout_mutex);
	message_queue.push(message);
	printMessages(); // Вызов функции printMessages должен быть также защищен мьютексом
}

void createMailslot(const wchar_t* mailslotName) {
	HANDLE hMailslot = CreateMailslotW(mailslotName, 0, MAILSLOT_WAIT_FOREVER, NULL);
	if (hMailslot == INVALID_HANDLE_VALUE) {
		logMessage(L"Failed to create mailslot: " + to_wstring(GetLastError()));
		return;
	}

	logMessage(L"Mailslot created, waiting for messages...");
	wchar_t messageBuffer[256];
	DWORD bytesRead;
	BOOL result;

	while (true) {
		result = ReadFile(hMailslot, messageBuffer, sizeof(messageBuffer), &bytesRead, NULL);
		if (!result || bytesRead == 0) {
			logMessage(L"Failed to read from mailslot: " + to_wstring(GetLastError()));
			break;
		}
		messageBuffer[bytesRead / sizeof(wchar_t)] = L'\0';
		logMessage(wstring(L"Received message: ") + messageBuffer);
	}
	CloseHandle(hMailslot);
}

void CreateNamedPipeAndProcess(const wchar_t* pipeName) {
	HANDLE hPipe = CreateNamedPipeW(pipeName, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 1, 4096, 4096, 500, NULL);
	if (hPipe == INVALID_HANDLE_VALUE) {
		logMessage(L"Failed to create named pipe: " + to_wstring(GetLastError()));
		return;
	}

	logMessage(L"Named pipe created, waiting for client connection...");
	if (!ConnectNamedPipe(hPipe, NULL)) {
		logMessage(L"Failed to connect named pipe: " + to_wstring(GetLastError()));
		CloseHandle(hPipe);
		return;
	}

	double matrix[3][3] = {{1, 0, 0}, {0, 1, 1}, {0, 1, 2}};
	DWORD bytesWritten;
	if (!WriteFile(hPipe, matrix, sizeof(matrix), &bytesWritten, NULL)) {
		logMessage(L"Failed to write to pipe: " + to_wstring(GetLastError()));
	} else {
		logMessage(L"Matrix data sent to client.");
	}

	double determinant;
	DWORD bytesRead;
	if (ReadFile(hPipe, &determinant, sizeof(determinant), &bytesRead, NULL)) {
		logMessage(L"Received determinant: " + to_wstring(determinant));
	} else {
		logMessage(L"Failed to read from pipe: " + to_wstring(GetLastError()));
	}

	DisconnectNamedPipe(hPipe);
	CloseHandle(hPipe);
}

int main() {
	const wchar_t* pipeName = L"\\\\.\\pipe\\1337";
	const wchar_t* mailslotName = L"\\\\.\\mailslot\\1337";

	std::thread mailslotThread(createMailslot, mailslotName);
	std::thread pipeThread(CreateNamedPipeAndProcess, pipeName);

	mailslotThread.join();
	pipeThread.join();

	return 0;
}
