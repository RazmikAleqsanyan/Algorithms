#include <iostream>
#include <cstdlib>
#include "Functions.h"

int main() {
	int n = 0;
	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i) {
		arr[i] = std::rand();
	}
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	CombSort(arr, n);
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	int k = BinarySearch(arr, 10, 0, n);
	std::cout << k;
	system("pause");
	return 0;
}