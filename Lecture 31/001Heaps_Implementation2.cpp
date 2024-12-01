/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class maxHeap {

	vector<int> v; // internal repr. of the maxHeap

	// time : O(logn)

	void heapify(int i) { // if you call heapify at index i, you've to make sure its left and right subtrees are already heaps

		// fix the maxHeap prop. at the ith index

		int maxIdx = i; // assume the node at index i has the smallest value

		int leftIdx = 2 * i + 1;
		if (leftIdx < v.size() and v[leftIdx] > v[maxIdx]) {
			maxIdx = leftIdx;
		}

		int rightIdx = 2 * i + 2;
		if (rightIdx < v.size() and v[rightIdx] > v[maxIdx]) {
			maxIdx = rightIdx;
		}

		if (maxIdx != i) { // heap prop. is acutally is violated at index i
			swap(v[i], v[maxIdx]); // heap prop. is now fixed at the ith index
			heapify(maxIdx);
		}

	}

public:

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx = v.size() - 1; // idx of the newly inserted val / node
		int parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
		while (childIdx != 0 and v[childIdx] > v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
		}

	}
	// time : O(logn)

	void pop() {
		swap(v[0], v[v.size() - 1]); // const
		v.pop_back(); // const
		heapify(0); // logn, fixes the heap prop. at the root i.e. idx 0 which may have been violated due to swap
	}

	int top() { // time : O(1)
		return v[0]; // calling top() on an empty heap is undefined
	}

	int size() { // time : O(1)
		return v.size();
	}

	bool empty() { // time : O(1)
		return v.empty(); // v.size() == 0
	}

};

int main() {

	maxHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl; // 9

	while (!m.empty()) {
		cout << m.top() << " "; // 1 2 3 4 5 6 7 8 9
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl; // 0

	return 0;
}



