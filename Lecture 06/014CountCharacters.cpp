#include<iostream>

using namespace std;

int main() {

	int cnt = 0; // to track the no. of characters

	char ch;

	while (true) {

		// cin >> ch; // ignores whitespaces (' ', '\n', '\t')

		ch = cin.get();

		if (ch == '$') {
			break;
		}

		cnt++;

	}

	cout << "cnt = " << cnt << endl;

	return 0;
}