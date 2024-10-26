// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int arr[], int s, int e) {

	int pivot = arr[e];
	int i = s;
	int j = i - 1; // boundary of the left part

	// while (i < e) {
	// 	if (arr[i] > pivot) { // arr[i] should go in the right part
	// 		i++;
	// 	} else { // arr[i] should go in the left part
	// 		j++;
	// 		swap(arr[i], arr[j]);
	// 		i++;
	// 	}
	// }

	while (i < e) {
		if (arr[i] < pivot) { // arr[i] should go in the left part
			j++;
			swap(arr[i], arr[j]);
		}
		i++;
	}

	swap(arr[e], arr[j + 1]); // j+1 is the correct position of the pivot
	return j + 1;

}

void quickSort(int arr[], int s, int e) {

	// base case

	if (s > e) {
		return;
	}

	if (s == e) {
		return;
	}

	// recursive case

	// 1. partition the arr[s...e] around the pivot

	int pidx = partition(arr, s, e);

	// 2. recursively sort the left and right part around the pivot

	quickSort(arr, s, pidx - 1);
	quickSort(arr, pidx + 1, e);

}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}