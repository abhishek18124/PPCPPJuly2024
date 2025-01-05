/*

given a non-negative number n, find the nth fibonacci no.

Example :
	Input : n = 7
	Output : 13

*/

#include<iostream>
#include<vector>

using namespace std;

int cnt1 = 0;

int f(int n) {

	cnt1++;

	// base case

	if (n == 0 || n == 1) {

		// f(0) : find the 0th fibonacci no.

		// f(1) : find the 1st fibonacci no.

		return n;

	}

	// recursive case

	// f(n) : find the nth fibonacci no.

	return f(n - 1) + f(n - 2);
}

int cnt2 = 0;


// time : O(n)
// space: O(n) due to dp[] and fn call stk

int fTopdown(int n, vector<int>& dp) {

	cnt2++;

	// lookup
	if (dp[n] != -1) {
		// you've already solved f(n)
		return dp[n];
	}

	// base case

	if (n == 0 || n == 1) {

		// f(0) : find the 0th fibonacci no.

		// f(1) : find the 1st fibonacci no.

		return dp[n] = n;

	}

	// recursive case

	// f(n) : find the nth fibonacci no.

	return dp[n] = fTopdown(n - 1, dp) + fTopdown(n - 2, dp);
}

// time : O(n)
// space: O(n) due to dp[]

int fBottomUp(int n) {

	vector<int> dp(n + 1);

	dp[0] = 0; // at 0th index of dp[] we store f(0)
	dp[1] = 1; // at 1st index of dp[] we store f(1)

	for (int i = 2; i <= n; i++) {

		// dp[i] = f(i) = ith fib. no.

		dp[i] = dp[i - 1] + dp[i - 2];

	}

	return dp[n]; // at the nth index of dp[] we store f(n) i.e.
	// result of the org. problem

}

// time : O(n)
// space: O(1)

int fBottomUpSpaceOptimised(int n) {

	if (n == 0 || n == 1) {
		return n;
	}

	int a = 0; // f(0)
	int b = 1; // f(1)

	for (int i = 2; i <= n; i++) {
		int c = a + b;
		a = b;
		b = c;
	}

	return b;

}

int main() {

	int n = 20;

	cout << f(n) << endl;

	vector<int> dp(n + 1, -1);

	cout << fTopdown(n, dp) << endl;

	cout << cnt1 << endl;
	cout << cnt2 << endl;

	cout << fBottomUp(n) << endl;

	cout << fBottomUpSpaceOptimised(n) << endl;

	return 0;
}