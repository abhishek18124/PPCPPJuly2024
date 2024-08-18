#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int i = 1;

	while (i <= n) {

		// for the ith row, print i stars

		int j = 1;

		while (j <= i) {

			cout << "*";
			j++;

		}

		cout << endl;

		i++;

	}

	return 0;

}