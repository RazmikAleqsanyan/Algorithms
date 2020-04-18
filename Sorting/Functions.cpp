#include "Functions.h"

void BubbleSort(int* arr, const int size) {
	int tmp = 0;		// for swapping
	for (int i = 0; i < size; ++i) {
		for (int j = 1; j < size - i; ++j) {
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

void CocktailSort(int* arr, const int size) {      // two sided bubble sort
	int Left = 0, Right = size - 1;    // for sorted parts in the end and in the begining
	int tmp = 0;		// for swapping
	while (Left <= Right) {
		for (int i = Left + 1; i <= Right; ++i) {
			if (arr[i - 1] > arr[i]) {
				tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
			}
		}
		--Right;
		for (int i = Right; i > Left; --i) {
			if (arr[i - 1] > arr[i]) {
				tmp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = tmp;
			}
		}
		++Left;
	}
}

 void InsertionSort(int* arr, const int size) {
	int current = 0;
	for (int i = 1; i < size; ++i) {
		current = arr[i];
		int j = i;
		while(current < arr[j - 1] && j > 0) {
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = current;
	}
}

void GnomeSort(int* arr, const int size) {
	int tmp = 0;		// for swapping
	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr[j] < arr[j - 1]) {
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

/*Merge sort*/
void Merge(int* arr, int begin, int middle, int end) {
	const int size1 = middle - begin;
	const int size2 = end - middle;
	int* arr1 = new int[size1];
	int* arr2 = new int[size2];
	for (int i = 0; i < size1; ++i) {
		arr1[i] = arr[begin + i];
	}
	for (int i = 0; i < size2; ++i) {
		arr2[i] = arr[middle + i];
	}
	 
	int i = 0, j = 0, k = 0;    // for iteration
	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j]) {
			arr[begin + k++] = arr1[i++];
		}
		else {
			arr[begin + k++] = arr2[j++];
		}
	}

	while (i < size1) {
		arr[begin + k++] = arr1[i++];
	}
	while (j < size2) {
		arr[begin + k++] = arr2[j++];
	}
	delete[] arr1;
	delete[] arr2;
}

void MergeSort(int* arr, int begin, int end) {
	if (begin + 1 < end) {
		int middle = (begin + end) / 2;
		MergeSort(arr, begin, middle);
		MergeSort(arr, middle, end);
		Merge(arr, begin, middle, end);
	} 
}
/*End of Merge sort*/

void TimSort(int*, const int);

void SelectionSort(int* arr, const int size) {
	int tmp = 0;		// for swapping
	int current = 0;
	for (int i = 0; i < size; ++i) {
		current = i;
		for (int j = 1 + i; j < size; ++j) {
			if (arr[j] < arr[current]) {
				current = j;
			}
		}
		if (i != current) {
			tmp = arr[current];
			arr[current] = arr[i];
			arr[i] = tmp;
		}
	}
}

void CombSort(int* arr, const int size) {
	double shr = 1.247;			//optimal shrink factor
	int tmp = 0;		// for swapping
	int distance = size / shr;
	bool isSorted = false;
	while (distance > 1 || !isSorted) {
		isSorted = true;
		for (int i = 0, j = i + distance; j < size; ++i, ++j) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				isSorted = false;
			}
		}
		distance = (distance > 1) ? distance / shr : 1; 
	}
}

void ShellSort(int* arr, const int size) {

}

int gap(const int) {
	return 0;
}

/*Quick sort*/
void QuickSort(int* arr, int begin, int end) {		//Hoare partition scheme
	
}
/*End of Quick sort*/