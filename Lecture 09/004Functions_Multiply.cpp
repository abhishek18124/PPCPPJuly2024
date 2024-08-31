#include<iostream>

using namespace std;

int multiply(int a, int b) {

	int c = a * b;
	return c;

	// return a * b;

}

int main() {

	cout << multiply(2, 3) << endl;

	cout << multiply(4, 5) << endl;

	cout << 10 * multiply(6, 7) << endl;

	int ans = multiply(2, 3);

	cout << ans + 1 << endl;

	return 0;
}