#include<iostream>

using namespace std;

// time : O(n)
// space: O(1)

int rainwater2Pointer(int h[], int n) {

	int i = 0;
	int j = n - 1;

	int total = 0;

	int l = 0; // represents max(0 to i)
	int r = 0; // represents max(j to n-1)

	while (i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if (l < r) {

			int wi = l - h[i];
			total += wi;
			i++;

		} else {

			int wj = r - h[j];
			total += wj;
			j--;

		}

	}

	return total;

}

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	cout << rainwater2Pointer(h, n) << endl;

	return 0;
}