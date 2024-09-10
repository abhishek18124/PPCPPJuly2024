#include<iostream>

using namespace std;

// time : O(n^2)
// space: O(1)

int rainwater(int h[], int n) {

	int total = 0; // to track the total water trapped b/w the buildings

	for (int i = 0; i < n; i++) {

		// find the water trapped on top of the ith building i.e. wi

		// li = max(0 to i)

		int li = h[i];

		for (int j = 0; j <= i - 1; j++) {
			li = max(li, h[j]);
		}

		// ri = max(i to n-1)

		int ri = h[i];

		for (int j = i + 1; j <= n - 1; j++) {
			ri = max(ri, h[j]);
		}

		int wi = min(li, ri) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwater(h, n) << endl;

	return 0;
}