#include<iostream>

using namespace std;

int main() {

	int n = 10;

	int mask = n - 1;

	(n & mask) == 0 ? cout << n << " is power of 2" << endl :
	                       cout << n << " is not a power of 2" << endl;

	return 0;
}