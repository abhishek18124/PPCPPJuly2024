/*

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year
you can sell the first or the last wine in the row. However, the price of wines increases
over time.

Let the initial prices of the wines be [p_1, p_2, ... , p_n]. In the yth year, the profit
from the kth wine will be y*p_k.

Find the maximum profit from all the wines.

Example :
	Input : prices[] = {2, 3, 5, 1, 4}
	Ouptut: 50

*/

#include<iostream>
#include<vector>

using namespace std;

int fStateOptimised(const vector<int>& p, int i, int j) {

	int y = p.size() - j + i;

	// base case

	if (i == j) {

		return y * p[i];

	}

	// recursive case

	return max(y * p[i] + fStateOptimised(p, i + 1, j),
	           y * p[j] + fStateOptimised(p, i, j - 1));

}

// time : O(n^2)
// space: O(n^2) due to dp[][]

int fStateOptimisedTopdown(const vector<int>& p, int i, int j, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	int y = p.size() - j + i;

	// base case

	if (i == j) {

		return dp[i][j] = y * p[i];

	}

	// recursive case

	return dp[i][j] = max(y * p[i] + fStateOptimisedTopdown(p, i + 1, j, dp),
	                      y * p[j] + fStateOptimisedTopdown(p, i, j - 1, dp));

}

// time : O(n^2)
// space: O(n^2)
// [HW] try to optimise space to O(n)

int fStateOptimisedBottomUp(const vector<int>& p, int n) {

	vector<vector<int>> dp(n, vector<int>(n));

	for (int i = 0; i < n; i++) {

		dp[i][i] = n * p[i]; // base case

		// int y = n;
		// int j = i;
		// dp[i][j] = y * p[i];

	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {

			// dp[i][j] = f(i, j)

			int y = n - j + i;
			dp[i][j] = max(y * p[i] + dp[i + 1][j],
			               y * p[j] + dp[i][j - 1]);

		}
	}

	return dp[0][n - 1]; // at the 0,n-1th index we store f(0, n-1)

}

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << fStateOptimised(p, 0, n - 1) << endl;

	vector<vector<int>> dp(n, vector<int>(n, -1));

	cout << fStateOptimisedTopdown(p, 0, n - 1, dp) << endl;

	cout << fStateOptimisedBottomUp(p, n) << endl;

	return 0;
}