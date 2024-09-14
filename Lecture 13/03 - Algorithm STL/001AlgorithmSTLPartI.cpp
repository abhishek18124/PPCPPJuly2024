#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int arr[] = {50, 40, 40, 30, 30, 30, 20, 10, 10};
	int n = sizeof(arr) / sizeof(int);

	// 1. sorting a sequence using built-in sort() in O(nlogn) // introsort used

	// sort(begin, end); // [begin, end)

	sort(arr, arr + n); // sort arr[0...n) i.e. sort arr[0...n-1]

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// int brr[] = {50, 40, 30, 20, 10};

	// sort(brr + 1, brr + 4); // sorts brr[1...4) i.e. brr[1...3]

	// for (int i = 0; i < 5; i++) {
	// 	cout << brr[i] << " ";
	// }

	// cout << endl;

	// 2. reversing a sequence using the built-in reverse()

	// reverse(begin, end); // [begin, end)

	reverse(arr, arr + n); // reverses the arr[0...n) i.e. arr[0...n-1]

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	// 3. reversing a sequence in-range using the built-in reverse()

	int crr[] = {10, 20, 30, 40, 50};
	int m = 5;

	reverse(crr + 2, crr + m);

	for (int i = 0; i < m; i++) {
		cout << crr[i] << " ";
	}

	cout << endl;

	return 0;
}
