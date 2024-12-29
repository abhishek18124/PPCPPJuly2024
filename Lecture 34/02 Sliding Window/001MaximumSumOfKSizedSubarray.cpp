#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 4, 2, 7, 6, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	// time : k + (n-k) ~ O(n)
	// space: O(1)

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the window

	int w_sum = 0; // to store the window sum

	// compute the sum of 1st window

	while (j < k) { // k-steps

		w_sum += arr[j];
		j++;

	}

	int max_sum_so_far = w_sum;   // to track the maximum window sum

	// compute the sum for the remaining windows
	while (j < n) { // n-k steps

		// slide the window
		w_sum -= arr[i];
		i++;
		w_sum += arr[j];

		max_sum_so_far = max(max_sum_so_far, w_sum);

		j++;

	}

	cout << max_sum_so_far << endl;

	return 0;
}

