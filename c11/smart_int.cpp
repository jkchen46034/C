/*
 * g++ -Wall  smart_int.cpp -std=c++11  -o smart_int 
 * time ./smartint
 */

#include <iostream>

class SmartInt {
public:
	int *p;
	explicit SmartInt(int *in = NULL) {p = in;}
	~SmartInt() {delete p;}
	int& operator *() {return *p;}
};

int main() {
	SmartInt p(new int());
	*p = 20;
	std::cout << *p;
}

