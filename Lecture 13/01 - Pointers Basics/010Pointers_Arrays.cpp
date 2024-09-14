#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// cout << arr << " " << &arr[0] << endl;
	// cout << arr + 1 << " " << &arr[1] << endl;
	// cout << arr + 2 << " " << &arr[2] << endl;

	for (int i = 0; i < n; i++) {
		cout << arr + i << " " << &arr[i] << " " << *(arr + i) << " " << arr[i] << endl;
	}

	return 0;
}