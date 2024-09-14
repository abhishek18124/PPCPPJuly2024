#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// 1. finding the minimum value in a sequence

	cout << *max_element(arr, arr + n) << endl;

	// 2. finding the maximum value in a sequence

	cout << *min_element(arr, arr + n) << endl;

	return 0;
}
