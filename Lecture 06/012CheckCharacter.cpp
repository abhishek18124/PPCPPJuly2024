#include<iostream>

using namespace std;

int main() {

	char ch;
	cin >> ch;

	if (ch >= 'a' and ch <= 'z') {

		cout << "lowercase" << endl;

	} else if (ch >= 'A' and ch <= 'Z') {

		cout << "uppercase" << endl;

	} else if (ch >= '0' and ch <= '9') {

		cout << "digit" << endl;

	} else {

		cout << "special" << endl;

	}


	if (ch >= 97 and ch <= 122) {

		cout << "lowercase" << endl;

	} else if (ch >= 65 and ch <= 90) {

		cout << "uppercase" << endl;

	} else if (ch >= 48 and ch <= 57) {

		cout << "digit" << endl;

	} else {

		cout << "special" << endl;

	}

	return 0;
}