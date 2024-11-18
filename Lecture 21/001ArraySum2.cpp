#include<iostream>

using namespace std;

int f(int X[], int s, int e) {

	// base case

	if (s == e) {

		// f(s, s) = find the sum(X[s...s]) = sum({X[s]})

		return X[s]; // return X[e];

	}

	// recursive case

	// f(s,e) = find the sum(X[s...e])

	int m = s + (e - s) / 2;

	// 1. ask your friend to find the sum(X[s...m])

	int A = f(X, s, m);

	// 2. ask your friend to find the sum(X[m+1...e])

	int B = f(X, m + 1, e);

	return A + B;

}

int main() {

	int X[] = {1, 2, 3, 4, 5};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, 0, n - 1) << endl;

	return 0;
}