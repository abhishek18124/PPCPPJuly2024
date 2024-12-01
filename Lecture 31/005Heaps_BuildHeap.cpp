/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap in-place.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) { // if you call heapify at index i, you've to make sure its left and right subtrees are already heaps

	// fix the maxHeap prop. at the ith index

	int maxIdx = i; // assume the node at index i has the smallest value

	int leftIdx = 2 * i + 1;
	if (leftIdx < n and v[leftIdx] > v[maxIdx]) {
		maxIdx = leftIdx;
	}

	int rightIdx = 2 * i + 2;
	if (rightIdx < n and v[rightIdx] > v[maxIdx]) {
		maxIdx = rightIdx;
	}

	if (maxIdx != i) { // heap prop. is acutally is violated at index i
		swap(v[i], v[maxIdx]); // heap prop. is now fixed at the ith index
		heapify(v, n, maxIdx);
	}

}

int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	for (int i = n - 1; i >= 0; i--) { // time : O(n)
		heapify(v, n, i);
	}


	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}





