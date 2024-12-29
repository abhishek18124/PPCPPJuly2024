#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = { -2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window
	queue<int>  q; // to store negative numbers in a window
	vector<int> v; // to store first negative number for each k-sized window

	// time : O(n)
	// space: O(k) if a window has only -ve nos.

	// find the first negative number in the 1st window

	while (j < k) { // k-steps
		if (arr[j] < 0) q.push(arr[j]);
		j++;
	}

	if (q.empty()) {
		// current window has no negatives
		v.push_back(0);
	} else {
		v.push_back(q.front());
	}

	// find the first negative number in the remaining windows

	while (j < n) { // n-k steps

		// slide the window
		if (arr[i] < 0) q.pop();
		i++;
		if (arr[j] < 0) q.push(arr[j]);

		if (q.empty()) {
			// current window has no negatives
			v.push_back(0);
		} else {
			v.push_back(q.front());
		}

		j++;

	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
