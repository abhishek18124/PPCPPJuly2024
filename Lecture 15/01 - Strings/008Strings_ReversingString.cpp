#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {

	string s = "abc";
	reverse(s.begin(), s.end());
	cout << s << endl;

	string t = "uvwxyz";
	reverse(t.begin() + 1, t.begin() + 5); // [1, 5) i.e. [1, 4]
	cout << t << endl;

	return 0;
}