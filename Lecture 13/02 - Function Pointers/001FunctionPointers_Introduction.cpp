#include<iostream>

using namespace std;

void greet() {
	cout << "namaste" << endl;
}

int add(int a, int b) {
	return a + b;
}

bool ascending(int a, int b) {
	return a > b; // return true if a > b otherwise return false
}

int main() {

	void (*gptr)() = &greet;
	int (*aptr)(int, int) = &add;
	bool (*ascptr)(int , int) = &ascending;

	// & is optional while accessing addresses of function

	cout << (void*)&greet << " " << (void*)greet << " " << (void*)gptr << endl;
	cout << (void*)&add << " " << (void*)add << " " << (void*)aptr << endl;
	cout << (void*)&ascending << " " << (void*)ascending <<  " " << (void*)ascptr << endl;


	greet();
	(*greet)();
	(*gptr)();
	gptr();

	cout << add(2, 3) << endl;
	cout << (*add)(2, 3) << endl;
	cout << (*aptr)(2, 3) << endl;
	cout << aptr(2, 3) << endl;

	cout << ascending(10, 5) << endl;
	cout << (*ascending)(10, 5) << endl;
	cout << (*ascptr)(10, 5) << endl;
	cout << ascptr(10, 5) << endl;

	// deref a fn ptr to call a fn is optional

	return 0;
}