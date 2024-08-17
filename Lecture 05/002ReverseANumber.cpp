#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int rev = 0; // to store the reverse of 'n'

	while (n > 0) {
		// int d = n % 10;
		// rev = rev * 10 + d;

		rev = rev * 10 + (n % 10);
		n = n / 10;
	}

	cout << rev << endl;

	return 0;
}