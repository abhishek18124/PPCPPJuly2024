#include<iostream>
#include<algorithm>

using namespace std;

// time : O(n^2)

int mostWater(int h[], int n) {

	int maxSoFar = 0; // INT_MIN

	for (int i = 0; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			// find the area of the container formed using the ith and jth line
			int width_ij = j - i;
			int height_ij = min(h[i], h[j]);
			int area_ij = width_ij * height_ij;
			maxSoFar = max(maxSoFar, area_ij);
		}
	}

	return maxSoFar;

}

// time : O(n)

int mostWaterOptimised(int h[], int n) {

	int i = 0;
	int j = n - 1;

	int maxSoFar = 0; // INT_MIN

	while (i < j) {
		int width_ij = j - i;
		int height_ij = min(h[i], h[j]);
		int area_ij = width_ij * height_ij;
		maxSoFar = max(maxSoFar, area_ij);

		if (h[i] < h[j]) {
			i++;
		} else {
			j--;
		}
	}

	return maxSoFar;

}

int main() {

	int h[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(h) / sizeof(int);

	cout << mostWater(h, n) << endl;

	cout << mostWaterOptimised(h, n) << endl;

	return 0;
}