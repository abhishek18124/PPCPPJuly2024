#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		cout << n << endl;

	} else {

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		int i = 2;

		while (i <= n) {
			int c = a + b;
			a = b;
			b = c;
			i = i + 1;
		}

		// cout << c << endl; // error // c is out of scope
		cout << b << endl;

	}

	return 0;
}