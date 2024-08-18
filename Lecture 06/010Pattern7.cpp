#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		// for the ith row print n-i spaces

		for (int j = 1; j <= n - i; j++) {
			cout << "  ";
		}

		// followed by i nos. in inc. order starting with i

		int num = i;

		for (int j = 1; j <= i; j++) {
			cout << num << " ";
			num++;
		}

		// followed by i-1 more nos. in dec. order starting with 2i-2

		// num = 2 * i - 2;
		num = num - 2;

		for (int j = 1; j <= i - 1; j++) {
			cout << num << " ";
			num--;
		}

		cout << endl;

	}

	return 0;
}