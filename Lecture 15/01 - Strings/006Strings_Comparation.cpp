#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "xyz";
	string t = "ayz";

	if (s < t) {

		cout << s << " < " << t << endl;

	} else {

		cout << s << " > " << t << endl;

	}

	cout << s.compare(t) << endl;
	cout << 'x' - 'a' << endl;

	int ans = s.compare(t);

	if (ans > 0) {
		cout << s << " > " << t << endl;
	} else if (ans < 0) {
		cout << s << " < " << t << endl;
	} else {
		cout << s << " is equal to " << t << endl;
	}

	return 0;
}