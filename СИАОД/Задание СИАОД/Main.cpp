#include <iostream>
#include <ctime>

using namespace std;

void selectionSort(int* arr, int length, bool swapFlag = false) {
	unsigned int start_time = clock();
	unsigned long counterSwap = 0;
	unsigned long counterIterations = 0;
	for (int i = 0; i < length - 1; ++i) {
		counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
		int minIndex = i;
		for (int j = i + 1; j < length; ++j) {
			counterIterations = swapFlag ? counterIterations + 1 : counterIterations;
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex]);
		counterSwap = swapFlag ? counterSwap + 1 : counterSwap;
	}
	unsigned long* info = new unsigned long[2];
	info[0] = counterSwap;
	info[1] = counterIterations;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "Time: " << search_time << endl;
	cout << "Swap: " << info[0] << endl;
	cout << "Iterations: " << info[1] << endl;
}


int main() {
	int n = 100;
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}

	selectionSort(arr, n, true);
	if (n < 1000000) {
		for (int j = 0; j < n; j++) {
			cout << arr[j] << "\t";
		}
	}
	return 0;
}