/*
 * g++ -Wall  thread.cpp -pthread -std=c++11  -o thread
 * time ./thread_fun
 */

#include <iostream>
#include <thread>

void func() {
	std::cout << "func()" << std::endl;
}

struct Functor {
	void operator()() const {
		std::cout << "functor()" << std::endl;
	}
};

int main() {
	std::thread t1(func);

	Functor functor;
	std::thread t2(functor);

	auto lambda = []()->void {
		std::cout << "lambda()" << std::endl;
	};
	std::thread t3(lambda);

	std::cout << "main()" <<std::endl;

	t1.join();
	t2.join();
	t3.join();

	return 0;
}

