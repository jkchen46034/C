/*
 * g++ -Wall  thread_val.cpp -pthread -std=c++11  -o thread_val_
 * time ./thread_val
 */

#include <iostream>
#include <thread>

void func(int i, double d, const std::string &s) {
	std::cout << i << ", " << d << ", " << s << std::endl;
}

int main() {
	std::thread t(func, 1, 12.50, "sample");
	t.join();

	return 0;
}

