#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// time : O(n)
// space: O(n) due to stack

vector<int> f(int A[], int n) {

	vector<int> ans;
	stack<int> s;

	for (int i = 0; i <= n - 1; i++) {

		// find the nearest greater element to the left of A[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {

			// there is no greater element to the left of A[i]
			ans.push_back(-1);

		} else {

			// whatever is at the top of the stack is the nearest greater element to the left of A[i]

			ans.push_back(s.top());

		}

		s.push(A[i]);

	}

	return ans;

}


int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = f(A, n);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;


	return 0;
}