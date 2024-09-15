#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {10, 10, 20, 30, 30, 30, 40, 40, 40, 40, 40, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// arr[] should sorted to use the following functions

	int key = 500;

	// 1. searching for a key in a sorted sequence in O(logn) using binary_search()

	binary_search(arr, arr + n, key) ? cout << key << " found" << endl :
	                                        cout << key << " not found" << endl;

	// 2. finding lower bound for a key in a sorted sequence in O(logn) using lower_bound()

	key = 40;

	auto lb = lower_bound(arr, arr + n, key);

	cout << lb - arr << endl;

	// 3. finding upper bound for a key in a sorted sequence in O(logn) using upper_bound()

	auto ub = upper_bound(arr, arr + n, key);

	cout << ub - arr << endl;

	// 4. counting the occurences of a key in a sorted sequence in O(logn)

	cout << ub - lb << endl;

	return 0;
}