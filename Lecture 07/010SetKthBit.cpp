#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 4;

	int mask = 1 << k; // a << b = a * 2^b // 1 << k = 1 * 2^k = 2^k

	cout << (n | mask) << endl;

	return 0;
}