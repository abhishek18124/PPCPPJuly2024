#include<iostream>

using namespace std;

int main() {

	int n = 128;
	int cnt = 0; // to track the no. of set bits in 'n'

	while (n > 0) {

		int rightmostBit = n & 1;
		if (rightmostBit) {
			cnt++;
		}

		n = n >> 1;

	}

	cout << cnt << endl;

	return 0;
}