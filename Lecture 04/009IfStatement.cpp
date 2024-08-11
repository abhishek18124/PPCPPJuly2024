#include<iostream>

using namespace std;

int main() {

	int age;
	cin >> age;

	if (age >= 18) {

		cout << "you can vote" << endl;

	}

	cout << "you are outside the if-block" << endl;

	return 0;
}