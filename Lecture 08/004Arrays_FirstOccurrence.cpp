#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 20;
	// int cnt = 0;
	bool flag = false; // assume t is not found

	for (int i = 0; i < n; i++) {

		if (arr[i] == t) {
			flag = true;
			// cnt++;
			cout << "1st occ of " << t << " is found at index " << i << endl;
			break;

		}

	}

	// if (cnt == 0) {
	// 	cout << -1 << endl;
	// }

	if (flag == false) {
		cout << -1 << endl;
	}

	return 0;
}