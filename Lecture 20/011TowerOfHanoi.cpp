#include<iostream>

using namespace std;

void f(int n, char src, char dst, char hlp) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to move n-1 disks from A(src) to B(hlp) using C(dst)

	f(n - 1, src, hlp, dst);

	// 2. move disk from A(src) to C(dst)

	cout << "move disk from " << src << " to " << dst << endl;

	// 3. ask your friend to move n-1 disks from B(hlp) to C(dst) using A(src)

	f(n - 1, hlp, dst, src);

}

int main() {

	int n = 3;

	f(n, 'A', 'C', 'B');

	return 0;

}