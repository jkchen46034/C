/*
 * g++ -Wall  smart_any.cpp -std=c++11  -o smart_any 
 * time ./smart_any
 */

#include <iostream>

template <class T>
class SmartPtr {
public:
	T *p;
	explicit SmartPtr(T *in = NULL) {p = in;}
	~SmartPtr() {delete p;}
	T& operator *() {return *p;}
	T* operator ->() {return p;}
};

int main() {
	SmartPtr<int> p(new int());
	*p = 20;
	std::cout << *p;
}

