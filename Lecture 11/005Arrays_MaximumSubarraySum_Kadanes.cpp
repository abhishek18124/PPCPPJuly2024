// constraints : n <= 100

#include<iostream>

using namespace std;

// time : O(n)
// space: O(n) due to x[]

int kadanes(int arr[], int n) {

	int x[100];

	x[0] = arr[0];
	int maxSoFar = x[0];

	for (int i = 1; i <= n - 1; i++) {
		x[i] = max(x[i - 1] + arr[i], arr[i]); // const
		maxSoFar = max(maxSoFar, x[i]); // const
	}

	return maxSoFar;

}


// time : O(n)
// space: O(1)

int kadanesSpaceOptimised(int arr[], int n) {

	int x;

	x = arr[0]; // x represents x[0]
	int maxSoFar = x;

	for (int i = 1; i <= n - 1; i++) {
		x = max(x + arr[i], arr[i]); // const
		maxSoFar = max(maxSoFar, x); // const
	}

	return maxSoFar;

}

int main() {

	int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << kadanes(arr, n) << endl;
	cout << kadanesSpaceOptimised(arr, n) << endl;

	return 0;
}