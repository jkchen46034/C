#include <iostream>

int find(int* a, int left, int right, int key) {
	while (left <= right) {
		int mid = (left + right) / 	2;
		if (key == a[mid]) {
			std::cout << "found " << a[mid] << ", at index: " << mid << std::endl;
			return 1;
		}	else if (key < a[mid]) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	std::cout << "not found! " << std::endl;
	return 1;
}

int main() {
	int a[] = { 1, 3, 5, 8, 10, 23, 31, 82};
	int left = 0;
	int right = sizeof(a)/sizeof(int) -1;
	std::cout << "finding 0, "; find(a, left, right, 0 );
	std::cout << "finding 28, "; find(a, left, right, 28);
	std::cout << "finding 5, "; find(a, left, right, 5);
	std::cout << "finding 82, "; find(a, left, right, 82);
	return 1;
}
/*
finding 0, not found! 
finding 28, not found! 
finding 5, found 5, at index: 2
finding 82, found 82, at index: 7
*/
