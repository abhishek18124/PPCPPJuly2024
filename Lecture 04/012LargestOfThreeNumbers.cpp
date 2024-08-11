#include<iostream>

using namespace std;

int main() {

	int a;
	cin >> a;

	int b;
	cin >> b;

	int c;
	cin >> c;

	if (a > b and a > c) {

		cout << a << endl;

	} else {

		// ans is either b or c

		if (b > c) {

			cout << b << endl;

		} else {

			cout << c << endl;

		}

	}

	if (a > b and a > c) {

		cout << a << endl;

	} else if (b > c) {

		cout << b << endl;

	} else {

		cout << c << endl;

	}

	return 0;
}