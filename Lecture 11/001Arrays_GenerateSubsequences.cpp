#include<iostream>

using namespace std;

void generateSubsequences(int arr[], int n) {

	for (int x = 0; x < (1 << n); x++) {

		cout << x << " = ";

		for (int k = 0; k < n; k++) {

			// check if the kth bit of x is set or not

			if ((x >> k) & 1) {

				// kth bit of x is set therefore use arr[k] in the subseq

				cout << arr[k] << " ";

			}

		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30};
	int n = sizeof(arr) / sizeof(int);

	generateSubsequences(arr, n);

	return 0;
}
