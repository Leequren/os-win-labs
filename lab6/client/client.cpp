#include <windows.h>
#include <iostream>
#include "../utils/utils.h"

using namespace std;

void ConnectToPipeAndProcess(const wchar_t* pipeName) {
	HANDLE hPipe = CreateFileW(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hPipe == INVALID_HANDLE_VALUE) {
		cerr << "CLIENT:Failed to open pipe: " << GetLastError() << endl;
		return;
	}

	// Чтение данных матрицы из канала
	double matrix[3][3];
	DWORD bytesRead;
	if (!ReadFile(hPipe, matrix, sizeof(matrix), &bytesRead, NULL) || bytesRead != sizeof(matrix)) {
		cerr << "CLIENT:Failed to read matrix data from pipe: " << GetLastError() << endl;
		CloseHandle(hPipe);
		return;
	}

	cout << "CLIENT:Matrix received from server." << endl;


	double determinant = CalculateDeterminant(matrix, 3);
	cout << "CLIENT:Determinant: " << determinant << endl;

	DWORD bytesWritten;
	if (!WriteFile(hPipe, &determinant, sizeof(determinant), &bytesWritten, NULL) || bytesWritten != sizeof(determinant)) {
		cerr << "CLIENT:Failed to send determinant to server: " << GetLastError() << endl;
	} else {
		cout << "CLIENT:Determinant sent back to server. Determinant is: " << determinant << endl;
	}

	CloseHandle(hPipe);
}

void SendMessageToMailslot(const wchar_t* mailslotName, const char* message) {
	HANDLE hMailslot = CreateFileW(mailslotName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hMailslot == INVALID_HANDLE_VALUE) {
		cerr << "CLIENT:Failed to open mailslot: " << GetLastError() << endl;
		return;
	}

	DWORD bytesWritten;
	if (!WriteFile(hMailslot, message, strlen(message), &bytesWritten, NULL) || bytesWritten != strlen(message)) {
		cerr << "CLIENT:Failed to send message to mailslot: " << GetLastError() << endl;
	} else {
		cout << "CLIENT:Message sent to mailslot." << endl;
	}

	CloseHandle(hMailslot);
}

int main() {
	const wchar_t* pipeName = L"\\\\.\\pipe\\1337";
	const wchar_t* mailslotName = L"\\\\.\\mailslot\\1337";

	ConnectToPipeAndProcess(pipeName);
	SendMessageToMailslot(mailslotName, "STOP");
	system("pause");
	return 0;
}
