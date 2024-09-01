#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int m = (s + e) / 2;

		if (arr[m] == t) { // t found at index m
			return m;
		} else if (t > arr[m]) {
			// reduce the search space from [s, e] to [m+1, e]
			s = m + 1;
		} else {
			// t < arr[m]
			// reduce the search space from [s, e] to [s, m-1]
			e = m - 1;
		}
	}

	return -1; // t not found

}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	cout << binarySearch(arr, n, t) << endl;

	return 0;
}