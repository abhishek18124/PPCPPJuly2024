#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> f1(int A[], int n) {

	vector<int> ans;
	stack<int> s; // index

	for (int i = 0; i <= n - 1; i++) {

		// find the index of nearest smaller element to the left of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the left of A[i]
			ans.push_back(-1);
		} else {
			// whatever index is at the top of the stack, it is the index of the nearest smaller element to the left of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	return ans;

}

vector<int> f2(int A[], int n) {

	vector<int> ans;
	stack<int> s; // index

	for (int i = n - 1; i >= 0; i--) {

		// find the index of nearest smaller element to the right of A[i]

		while (!s.empty() and A[s.top()] >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// there is no smaller element to the right of A[i]
			ans.push_back(n);
		} else {
			// whatever index is at the top of the stack, it is the index of the nearest smaller element to the right of A[i]
			ans.push_back(s.top());
		}

		s.push(i);

	}

	reverse(ans.begin(), ans.end());

	return ans;

}

int main() {

	int h[] = {2, 1, 5, 6, 2, 3};
	int n = sizeof(h) / sizeof(int);

	vector<int> nsl = f1(h, n); // n-steps
	vector<int> nsr = f2(h, n); // n-steps

	int maxSoFar = 0;

	for (int i = 0; i < n; i++) { // n-steps
		// find the largest area possible if the height of rectangle is h[i]
		int bestWidth = nsr[i] - nsl[i] - 1;
		int bestArea = h[i] * bestWidth;
		cout << "bestArea(h=" << h[i] << ") = " << bestArea << endl;
		maxSoFar = max(maxSoFar, bestArea);

	}

	// 3n-steps.const time : O(n)
	// space : O(n)

	cout << maxSoFar << endl;

	return 0;
}