#include<iostream>

using namespace std;

void mySwap(int& aRef, int& bRef) {
	int temp = aRef;
	aRef = bRef;
	bRef = temp;
}

int main() {

	int a = 10;
	int b = 20;

	cout << a << " " << b << endl;

	mySwap(a, b);

	cout << a << " " << b << endl;

	return 0;
}