#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int i = 0;
	int j = n - 1; // you don't need j since it is fixed

	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}