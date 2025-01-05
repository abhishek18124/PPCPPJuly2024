/*

Given a number n, count the minimum steps to reduce n to 1
such that at each step you may

	reduce n to n/2 if n is divisible by 2
	or reduce n to n/3 if n is divisible by 3
	or reduce n to n-1 by decrementing n by 1

Example :
	Input : n = 10
	Output : 3

	Input : 6
	Output : 2

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int cnt1 = 0;

int f(int n) {

	cnt1++;

	// base case

	if (n == 1) {

		// f(1) = count min. no. of steps required to reduce 1 to 1

		return 0;

	}

	// recursive case

	// f(n) = count min. no. of steps requried to reduce n to 1

	// decide the next step

	// option 1 : reduce n to n-1

	int op1 = f(n - 1);

	// option 2 : reduce n to n/2 if n%2 == 0

	int op2 = INT_MAX;
	if (n % 2 == 0) {
		op2 = f(n / 2);
	}

	// option 3 : reduce n to n/3 if n%3 == 0

	int op3 = INT_MAX;
	if (n % 3 == 0) {
		op3 = f(n / 3);
	}

	return 1 + min(op1, min(op2, op3));

}

int cnt2 = 0;

int fTopDown(int n, vector<int>& dp) {

	cnt2++;

	// lookup

	if (dp[n] != -1) {
		// you've already solve f(n)
		return dp[n];
	}

	// base case

	if (n == 1) {

		// f(1) = count min. no. of steps required to reduce 1 to 1

		return dp[n] = 0;

	}

	// recursive case

	// f(n) = count min. no. of steps requried to reduce n to 1

	// decide the next step

	// option 1 : reduce n to n-1

	int op1 = fTopDown(n - 1, dp);

	// option 2 : reduce n to n/2 if n%2 == 0

	int op2 = INT_MAX;
	if (n % 2 == 0) {
		op2 = fTopDown(n / 2, dp);
	}

	// option 3 : reduce n to n/3 if n%3 == 0

	int op3 = INT_MAX;
	if (n % 3 == 0) {
		op3 = fTopDown(n / 3, dp);
	}

	return dp[n] = 1 + min(op1, min(op2, op3));

}

// time : O(n)
// space: O(n)

int fBottomUp(int n) {

	vector<int> dp(n + 1); // 0th index is not used

	dp[1] = 0; // at the 1st index of dp[] we store f(1)

	for (int i = 2; i <= n; i++) {

		// dp[i] = f(i) = min. steps required to reduce i to 1

		// decide the next step

		// option 1 : reduce i to i-1

		int op1 = dp[i - 1];

		// option 2 : reduce i to i/2 if i%2 == 0

		int op2 = INT_MAX;
		if (i % 2 == 0) {
			op2 = dp[i / 2];
		}

		// option 3 : reduce i to i/3 if i%3 == 0
		int op3 = INT_MAX;
		if (i % 3 == 0) {
			op3 = dp[i / 3];
		}

		dp[i] = 1 + min(op1, min(op2, op3));

	}

	return dp[n]; // at the nth index of dp[] we store f(n)

}

int main() {

	int n = 100;

	cout << f(n) << endl;

	vector<int> dp(n + 1, -1); // 0th idx is not used since we'll never encounter f(0)

	cout << fTopDown(n, dp) << endl;

	cout << cnt1 << endl << cnt2 << endl;

	cout << fBottomUp(n) << endl;

	return 0;
}