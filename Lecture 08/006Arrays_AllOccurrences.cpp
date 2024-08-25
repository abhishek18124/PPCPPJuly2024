#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	bool flag = false; // assume t is not found

	for (int i = 0; i < n; i++) {
		if (arr[i] == t) {
			flag = true;
			cout << t << " found at index " << i << endl;
		}
	}

	if (flag == false) {
		cout << -1 << endl;
	}


	if (!flag) { // !false // true
		cout << -1 << endl;
	}

	return 0;
}