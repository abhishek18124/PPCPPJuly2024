#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 3;

	if (((n >> k) & 1) == 1) {
		cout << "bit " << k << " of " << n << " is set" << endl;
	} else {
		cout << "bit " << k << " of " << n << " is not set" << endl;
	}

	if (((1 << k) & n) == 0) {
		cout << "bit " << k << " of " << n << " is not set" << endl;
	} else {
		cout << "bit " << k << " of " << n << " is set" << endl;
	}

	return 0;
}