#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row, print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << " ";
		}

		// followed by i stars

		for (int j = 1; j <= i; j++) {
			cout << "*";
		}

		cout << endl;

	}

	return 0;
}