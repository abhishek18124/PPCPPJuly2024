#include<iostream>
#include<string>

using namespace std;

bool isGoodString(const string& str) {

	for (char ch : str) {
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {
			// ch is a consonant
			return false; // str is not a good string
		}
	}

	return true; // str is a good string

}

// time : O(n^3)

int longestGoodSubstring(const string& str) { // str is passed by const reference to avoid copy & modification

	int n = str.size();
	int maxSofar = 0;

	string ans = "";

	for (int i = 0; i <= n - 1; i++) {

		for (int j = i; j <= n - 1; j++) {

			// check if the substring that starts at the ith index and ends at the jth index is a good substring or not

			string subString = str.substr(i, j - i + 1);
			if (isGoodString(subString)) {
				// maxSofar = max(maxSofar, j - i + 1);
				if (j - i + 1 > maxSofar) {
					maxSofar = j - i + 1;
					ans = subString;
				}
				// cout << subString << " " << ans << endl;
			}

		}

	}

	cout << ans << endl;

	return maxSofar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstring(str) << endl;

	return 0;
}