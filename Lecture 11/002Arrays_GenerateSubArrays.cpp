#include<iostream>

using namespace std;

void generateSubarrays(int arr[], int n) {

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// generate the subarray that starts at the ith index and ends at the jth index

			// cout << i << " " << j << endl;

			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}

			cout << endl;



		}

		cout << endl;

	}

}

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	generateSubarrays(arr, n);

	return 0;
}