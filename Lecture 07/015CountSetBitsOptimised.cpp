#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cin >> n;

	int cnt = 0; // to track the no. of set bits in 'n'

	for (int k = 0; k < ceil(log2(n + 1)); k++) {

		// check if kth bit of n is set

		if ((n >> k) & 1) {
			cnt++;
		}

	}

	cout << cnt << endl;

	return 0;
}