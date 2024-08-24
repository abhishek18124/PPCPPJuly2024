#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {

		cnt++;

		// update n by clearing its rightmost set bit

		n = n & (n - 1);

	}

	cout << cnt << endl;

	return 0;
}