// contraints : n <= 100, k <= 9

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);

	int k = 3; // denotes the maximum element in the array

	// total steps = n(building freqMap) + n(building sorted arr from freqMap) = 2n ~ O(n)
	// total space = k+1 due to freq[] ~ O(k)

	int freq[10]; // based on constraints

	memset(freq, 0, sizeof(freq)); // init freq[] with 0

	for (int i = 0; i < n; i++) { // n-steps

		int x = arr[i];
		freq[x]++;

		// freq[arr[i]]++;

	}

	// for (int i = 0; i <= k; i++) {

	// 	cout << "freq(" << i << ") = " << freq[i] << endl;

	// }

	// cout << endl;

	for (int i = 0; i <= k; i++) { // n-steps

		int x = freq[i];

		// print i, x times

		for (int j = 1; j <= x; j++) {
			cout << i << " ";
		}

	}

	cout << endl;

	return 0;
}