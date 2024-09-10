// n<=100
#include<iostream>

using namespace std;

int rainwaterOptimised(int h[], int n) {

	// precompute l[]

	int l[100];
	l[0] = h[0];

	for (int i = 1; i <= n - 1; i++) {
		l[i] = max(h[i], l[i - 1]);
	}

	// precompute r[]

	int r[100];
	r[n - 1] = h[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		r[i] = max(h[i], r[i + 1]);
	}

	int total = 0; // to track the total water trapped b/w the buildings

	for (int i = 0; i < n; i++) {

		// find the water trapped on top of the ith building i.e. wi

		int wi = min(l[i], r[i]) - h[i];
		total += wi;

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwaterOptimised(h, n) << endl;

	return 0;
}