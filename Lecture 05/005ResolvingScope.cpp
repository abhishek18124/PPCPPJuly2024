#include<iostream>

using namespace std;

int main() {

	int x = 10;

	cout << x << endl;

	{
		int y = 20;

		cout << x << " " << y << endl;

	}

	cout << x << endl;
	// cout << y << endl; // y is out-of-scope i.e y is not in this scope

	return 0;
}