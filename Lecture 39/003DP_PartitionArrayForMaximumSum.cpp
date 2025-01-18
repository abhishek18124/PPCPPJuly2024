#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(const vector<int>& arr, int n, int k, int i) {

	// base case

	if (i == n) {
		return 0;
	}

	// recursive case

	// decide the next cut

	int maxSofar = INT_MIN;
	int maxij = arr[i]; // to store the max(arr[i...j])

	for (int j = i; j < i + k and j < n; j++) {
		maxij = max(maxij, arr[j]);
		maxSofar = max(maxSofar, (j - i + 1) * maxij + f(arr, n, k, j + 1));

	}

	return maxSofar;

}

int fBottomUp(const vector<int>& arr, int n, int k) {

	vector<int> dp(n + 1);

	dp[n] = 0; // at the nth index of dp[] we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		// dp[i] = f(i)

		// decide the next cut

		int maxSofar = INT_MIN;
		int maxij = arr[i]; // to store the max(arr[i...j])

		for (int j = i; j < i + k and j < n; j++) {
			maxij = max(maxij, arr[j]);
			maxSofar = max(maxSofar, (j - i + 1) * maxij + dp[j + 1]);

		}

		dp[i] = maxSofar;

	}

	return dp[0]; // at the 0th index of dp[] we store f(0)

}

int maxSumAfterPartitioning(vector<int>& arr, int k) {

	int n = arr.size();

	// return f(arr, n, k, 0);

	return fBottomUp(arr, n, k);
}

int main() {

	vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
	int k = 3;

	cout << maxSumAfterPartitioning(arr, k) << endl;

	return 0;
}