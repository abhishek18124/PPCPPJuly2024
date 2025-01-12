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

int f(const vector<int>& p, int i, int j, int y) {

	// base case

	if (i == j) { // y == p.size()

		return y * p[i];

	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle of wine

	// option 2 : sell the jth bottle of wine

	return max(y * p[i] + f(p, i + 1, j, y + 1),
	           y * p[j] + f(p, i, j - 1, y + 1));

}

// time : O(n^3)
// space: n^3 due to dp[][][] + n due to fn call stack ~ O(n^3)

int fTopdown(const vector<int>& p, int i, int j, int y, vector<vector<vector<int>>>& dp) {

	// lookup

	if (dp[i][j][y] != -1) {
		return dp[i][j][y];
	}

	// base case

	if (i == j) { // y == p.size()

		return dp[i][j][y] = y * p[i];

	}

	// recursive case

	// f(i, j, y) = find the maximum profit from wines[i...j] starting from year y

	// decide for the yth year

	// option 1 : sell the ith bottle of wine

	// option 2 : sell the jth bottle of wine

	return dp[i][j][y] = max(y * p[i] + fTopdown(p, i + 1, j, y + 1, dp),
	                         y * p[j] + fTopdown(p, i, j - 1, y + 1, dp));

}

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

int main() {

	vector<int> p = {2, 3, 5, 1, 4};
	int n = p.size();

	cout << f(p, 0, n - 1, 1) << endl;



	vector<vector<vector<int>>> dp(n,
	                               vector<vector<int>>(n,
	                                       vector<int>(n + 1, -1)));

	cout << fTopdown(p, 0, n - 1, 1, dp) << endl;

	cout << fStateOptimised(p, 0, n - 1) << endl;

	return 0;
}