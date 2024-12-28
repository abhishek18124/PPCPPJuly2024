#include<iostream>
#include<vector>
#include<set>

using namespace std;

// time : O(nlogn) since we are using a set<>
// time : on avg. O(n) if we use unordered_set<>
// space: O(n) if string contains distinct elements

int longestLengthPalindrome(const string& str) {

	set<char> s;
	int ans = 0;
	for (char ch : str) {
		if (s.find(ch) == s.end()) {
			// ch is not present
			s.insert(ch);
		} else {
			// ch is already present
			ans += 2;
			s.erase(ch);
		}
	}

	if (s.size() > 0) { // we've char. with odd freq, so use any one of them at the center of the longest palindrome you are building
		ans++;
	}

	return ans;

}


int main() {

	string str = "abccccdd";

	cout << longestLengthPalindrome(str) << endl;

	return 0;
}