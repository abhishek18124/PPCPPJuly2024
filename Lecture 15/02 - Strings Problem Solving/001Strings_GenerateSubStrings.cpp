#include<iostream>
#include<string>

using namespace std;

// for a string of size n, it has n(n+1) / 2 i.e. ~ n^2 substrings

void generateSubstring(string str, int n) {// string object are by-deault passed by value (expensive due to copy)

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// generate the substring that starts at the ith index and ends at the jth index

			// for (int k = i; k <= j; k++) {
			// 	cout << str[k];
			// }
			// cout << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}
		cout << endl;
	}

}

void generateSubstring2(const string& str, int n) {// string object are passed by const ref so you avoid the copy and also make sure str isn't modified within the fn

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// generate the substring that starts at the ith index and ends at the jth index

			// for (int k = i; k <= j; k++) {
			// 	cout << str[k];
			// }
			// cout << endl;

			cout << str.substr(i, j - i + 1) << endl;

		}
		cout << endl;
	}

}

int main() {

	string str = "abcde";
	int n = str.size();

	generateSubstring(str, n);

	return 0;
}