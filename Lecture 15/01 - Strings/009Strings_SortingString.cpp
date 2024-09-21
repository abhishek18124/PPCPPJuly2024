#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool myCmp(char a, char b) {

	if (a > b) {
		// since we are sorting in dec. order we want a to be ordered before b
		return true;
	}

	return false;

}

int main() {

	string s = "xabcyzd";
	sort(s.begin(), s.end());
	cout << s << endl;

	string t = "xaybzc";

	// sort(t.begin(), t.end(), greater<char>());
	// sort(t.rbegin(), t.rend());
	sort(t.begin(), t.end(), myCmp);

	cout << t << endl;


	return 0;
}