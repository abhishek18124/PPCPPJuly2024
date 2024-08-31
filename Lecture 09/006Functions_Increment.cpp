#include<iostream>

using namespace std;

void incrementByVal(int a) {
	cout << "inside increment() before ++ a = " << a << endl;
	a++;
	cout << "inside increment() after ++ a = " << a << endl;
}

void incrementByRef(int& ref) { // ref is like a new name for a defined in main()
	cout << "inside increment() before ++ a = " << ref << endl;
	ref++;
	cout << "inside increment() after ++ a = " << ref << endl;
}

int main() {

	int a = 0;

	cout << "inside main() before calling increment() a = " << a << endl;

	// incrementByVal(a);
	incrementByRef(a);

	cout << "inside main() after calling increment() a = " << a << endl;

	return 0;
}