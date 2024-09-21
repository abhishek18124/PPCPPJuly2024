#include<iostream>
#include<string>

using namespace std;

// time : O(n^2)
// space: O(1)

int countPalindromicSubstringsOptimised(const string& s) {

	int n = s.size();
	int cnt = 0; // to track the no. of palindromic substrings in the given string

	// 1. cnt no. of odd length palindromic substrings

	for (int i = 0; i <= n - 1; i++) {

		// cnt no. of odd length palindromic substrings around s[i]

		int j = 0;

		while (i - j >= 0 and i + j <= n - 1 and s[i - j] == s[i + j]) {
			cnt++;
			j++;
		}

	}

	// 2. cnt no. of even length palindromic substring

	for (double i = 0.5; i <= n - 1; i++) {

		// cnt no. of odd length palindromic substrings around s[i]

		double j = 0.5;

		while (i - j >= 0 and i + j <= n - 1 and s[(int)(i - j)] == s[(int)(i + j)]) {
			cnt++;
			j++;
		}

	}



	return cnt;

}

int main() {

	string s = "abaaba";

	cout << countPalindromicSubstringsOptimised(s) << endl;

	return 0;
}