#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	int key = 10;

	// 1. searching for a key in a sequence using find()

	auto it = find(arr, arr + n, key);

	// cout << it << endl;
	// cout << arr << endl;

	cout << it - arr << endl;

	key = 100;

	it = find(arr, arr + n, key);

	if (it == arr + n) {
		cout << key << "not found" << endl;
	}

	// 2. counting the occurrences of a key in a sequence using count()

	key = 30;

	int cnt = count(arr, arr + n, key);

	cout  << cnt << endl;

	return 0;
}
