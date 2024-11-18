#include<iostream>

using namespace std;

int f(string s, int n) {

	// base case

	if (n == 0) { // s.empty() // s == "" // s.size() == 0
		return 0;
	}

	// recursive case

	string subString = s.substr(0, n - 1);
	int integerFromMyFriend = f(subString, n - 1);
	return integerFromMyFriend * 10 + (s.back() - '0'); // s.back() or s[n-1]

}

int main() {

	string str = "12345";
	int n = str.size();

	cout << f(str, n) << endl;

	return 0;

}