#include<iostream>

using namespace std;

void isEven(int n) {

	if (n % 2 == 0) {
		cout << n << " is even" << endl;
	} else {
		cout << n << " is odd" << endl;
	}

}

int main() {

	isEven(5);

	isEven(4);

	return 0;
}