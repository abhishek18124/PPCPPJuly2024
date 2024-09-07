#include<iostream>
#include<algorithm>

using namespace std;

// time : O(n^2)

int countPairs(int arr[], int n, int t) {

	int cnt = 0; // to track no. of valid pairs

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			int pairSum = arr[i] + arr[j];
			if (pairSum == t) {
				cnt++;
			}
		}
	}

	return cnt;

}

// time : O(n)

int countPairsOptimised(int arr[], int n, int t) {

	int i = 0;
	int j = n - 1;

	int cnt = 0;

	while (i < j) {

		int pairSum = arr[i] + arr[j];
		if (pairSum > t) {
			j--;
		} else if (pairSum < t) {
			i++;
		} else {
			// you've found a valid pair
			cnt++;
			i++;
			j--;
		}
	}

	return cnt;

}

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	cout << countPairs(arr, n, t) << endl;

	cout << countPairsOptimised(arr, n, t) << endl;

	return 0;
}