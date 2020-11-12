/*
 * g++ -Wall  thread_val.cpp -pthread -std=c++11  -o thread_val_
 * time ./thread_val
 */

#include <iostream>
#include <thread>

void func(int& a) {
	a++;
}

int main() {
	int a = 42;
	std::thread t(func, std::ref(a));
	t.join();
	std::cout << a << std::endl;

	return 0;
}

