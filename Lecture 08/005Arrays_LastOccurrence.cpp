#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;
	int i;

	for (i = n - 1; i >= 0; i--) {

		if (arr[i] == t) {

			cout << "last occ of " << t << " found at index " << i << endl;
			break;

		}

	}

	if (i == -1) {
		cout << -1;
	}

	return 0;
}