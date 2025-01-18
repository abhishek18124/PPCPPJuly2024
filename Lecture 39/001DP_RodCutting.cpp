/*



Given a rod of length 'n' along with prices of its pieces of different lengths, design an algorithm to
compute the maximum profit we can make by cutting the rod and a selling its pieces.

Example :

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [1,  5,  8,  9,  10, 17, 17, 20]
	Output : 22

	Input : n = 8
	        length : [1,  2,  3,  4,  5,  6,  7,  8]
	        prices : [3,  5,  8,  9, 10, 17, 17, 20]
	Output : 24


*/


#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int f(int n, const vector<int>& p) {

	// base case

	if (n == 0) {

		// f(0) = find the max. profit given a rod of length 0

		return 0;

	}

	// recursive case

	// f(n) = find the max. profit given a rod of length n

	int maxSofar = 0;

	for (int j = 1; j <= n; j++) {

		maxSofar = max(maxSofar, p[j - 1] + f(n - j, p));

	}

	return maxSofar;

}

// time : O(n^2)
// space: O(n) due dp[]
// [HW] try to construct answer

int fBottomUp(int n, const vector<int>& p) {

	vector<int> dp(n + 1);

	dp[0] = 0; // at the 0th index of dp[] we store f(0)

	for (int i = 1; i <= n; i++) {

		// dp[i] = f(i) = it is fn that finds the max. profit given a rod of length i

		int maxSofar = 0;

		for (int j = 1; j <= i; j++) {

			maxSofar = max(maxSofar, p[j - 1] + dp[i - j]);

		}

		dp[i] = maxSofar;

	}

	return dp[n]; // at the nth index of dp[] we store f(n)

}

int main() {

	vector<int> p = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = p.size();

	cout << f(n, p) << endl;

	cout << fBottomUp(n, p) << endl;

	return 0;
}