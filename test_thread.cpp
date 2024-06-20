#include <iostream>
#include <thread>

void foo() {
	std::cout << "Thread function.\n";
}

int main() {
	std::thread thread(foo);
	thread.join();
	return 0;
}