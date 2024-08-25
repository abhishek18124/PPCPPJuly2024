#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;
	int i;

	// time : n.const ~ O(n)

	for (i = 0; i < n; i++) {

		if (arr[i] == t) { // const op.
			cout << "1st occ of " << t << " is found at index " << i << endl;
			break;

		}

	}

	if (i == n) {
		cout << -1 << endl;
	}

	return 0;
}