#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	int sqN = sqrt(n);

	int i = 2;
	while (i <= sqN) {

		if (n % i == 0) {

			// you've found a factor of n in the range [2, sqN]
			return false;

		}

		i++;

	}

	// n is a prime

	return true;

}

int main() {

	int n;
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl : cout << n << " is not prime" << endl;

	return 0;
}