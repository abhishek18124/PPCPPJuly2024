#include<iostream>

using namespace std;

// int* f1() {
// 	int x = 10;
// 	return &x;
// }


int* f2() {
	int* xptr = new int;
	*xptr = 10;
	return xptr;
}

int main() {

	// int* xptr1 = f1(); // xptr1 is a dangling pointer

	int* xptr2 = f2();
	cout << *xptr2 << endl;

	return 0;
}