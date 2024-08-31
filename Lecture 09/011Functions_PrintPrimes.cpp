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

// adv of fn

// 1. reusability
// 2. readability
// 3. modularity

void printPrimes(int m) {

	for (int n = 2; n <= m; n++) {

		// check if n is prime or not

		if (isPrime(n)) {

			// n is prime

			cout << n << " ";

		}

	}

	cout << endl;

}

int main() {

	int m;
	cin >> m;

	printPrimes(m);

	return 0;
}