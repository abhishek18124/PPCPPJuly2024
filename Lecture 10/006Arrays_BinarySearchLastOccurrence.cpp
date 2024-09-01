#include<iostream>

using namespace std;


int upperBound(int arr[], int n, int t) {

	int s = 0;
	int e = n - 1;

	int ans = -1;

	while (s <= e) {

		int m = s + (e - s) / 2;
		if (arr[m] == t) {

			ans = m;
			s = m + 1;

		} else if (t > arr[m]) {

			s = m + 1;

		} else {

			// t < arr[m]

			e = m - 1;

		}

	}

	return ans;

}


int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 30, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int t = 10;

	cout << upperBound(arr, n, t) << endl;

	return 0;
}