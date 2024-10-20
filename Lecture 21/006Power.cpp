#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// find x^0
		return 1;
	}

	// recursive case

	// find x^y

	// 1. ask your friend to find x^(y-1)

	int A = f(x, y - 1);

	return x * A;

}

int main() {

	int x = 2;
	int y = 3;

	cout << f(x, y) << endl;

	return 0;

}