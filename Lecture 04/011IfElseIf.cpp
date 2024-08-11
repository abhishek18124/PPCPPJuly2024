#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	if (n > 0) {
		cout << "positive" << endl;
	} else if (n < 0) {
		cout << "negative" << endl;
	} else {
		cout << "zero" << endl;
	}

	cout << "you are outside the if-else-if block" << endl;

	return 0;
}