#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cin >> n;

	int lsf = INT_MIN; // to track the "largest so far"
	int ssf = INT_MAX; // to track the "smallest so far"

	int i = 1;

	while (i <= n) {

		int x;
		cin >> x;

		if (x > lsf) {

			lsf = x;

		}

		if (x < ssf) {

			ssf = x;

		}

		// cout << "x = " << x << " lsf = " << lsf << endl;

		i = i + 1;

	}

	cout << lsf << endl;
	cout << ssf << endl;

	return 0;
}