#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int squareRoot = sqrt(n);

	int i = 2;

	while (i <= squareRoot) {

		if (n % i == 0) {

			cout << "not prime" << endl;
			break;

		}

		i = i + 1;

	}

	if (i > squareRoot) {

		cout << "prime" << endl;

	}

	return 0;
}