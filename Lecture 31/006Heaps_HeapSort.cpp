/*

	Given an array of n integers, sort the array using heap sort algorithm.

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

	// 1. transform v[] into a maxHeap // linear

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	// 2. now that v[] is transformed into a maxHeap, transform maxHeap into sorted v[] // nlogn

	int heapsize = n;
	while (heapsize > 1) { // n-1 times
		swap(v[0], v[heapsize - 1]); // const
		heapsize--; // const
		heapify(v, heapsize, 0); // logn, since we are calling heapify on the root node
	}

	// time : n + nlogn ~ O(nlogn)
	// space: O(logn) due to fn call stk used during heapify
	// space can be further reduced to O(1) if heapify is impl. iteratively [HW]

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}
