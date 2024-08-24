#include<iostream>

using namespace std;

int main() {

	int a = 5;
	int b = 3;

	a *= b - 1; // 14, 10

	// a = a * b - 1 // incorrect
	//   = 5 * 3 - 1
	//   = 15 - 1
	//   = 14

	// // a = a * (b-1) // correct
	//      = 5 * (3 - 1)
	//      = 10

	cout << a << endl;

	return 0;
}