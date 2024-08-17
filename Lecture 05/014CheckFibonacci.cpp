#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n == 0 || n == 1) {

		cout << "true" << endl;

	} else {

		int a = 0; // 0th fib. no.
		int b = 1; // 1st fib. no.

		while (true) {

			int c = a + b;

			cout << c << endl;

			if (c == n) {

				cout << "true" << endl;
				break;

			}

			if (c > n) {

				cout << "false" << endl;
				break;

			}

			// c < n

			a = b;
			b = c;

		}

	}

	return 0;
}