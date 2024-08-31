#include<iostream>

using namespace std;

void greet() {

	cout << "hello world" << endl;
	return; // optional

}

int main() {

	cout << "I am inside main(), before calling greet()" << endl;

	greet(); // fn call or fn invocation

	cout << "I am inside main(), after calling greet()" << endl;

	return 0;

}