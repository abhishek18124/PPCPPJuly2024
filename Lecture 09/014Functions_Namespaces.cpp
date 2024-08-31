#include<iostream>

using namespace std;

namespace add {

int f(int a, int b) {
	return a + b;
}

};

namespace mul {

int f(int a, int b) {
	return a * b;
}

};

int main() {

	cout << add::f(2, 3) << endl;
	cout << mul::f(2, 3) << endl;

	return 0;
}