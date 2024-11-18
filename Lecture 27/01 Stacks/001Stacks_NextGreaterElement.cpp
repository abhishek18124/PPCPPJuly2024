#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// time : O(n^2)
// space: O(1) (out[] space is not treated as auxiliary space)

vector<int> fBruteForce(int A[], int n) {

	vector<int> ans;

	for (int i = 0; i < n; i++) {

		// find the nearest greater element to the right of A[i]

		bool flag = false; // assume there is no greater element to the right of A[i]

		for (int j = i + 1; j < n; j++) {

			if (A[j] > A[i]) {

				// A[j] is the nearest greater element to the right of A[i]

				flag = true;
				ans.push_back(A[j]);
				break;

			}

		}

		if (flag == false) {

			// there is no greater element to the right of A[i]

			ans.push_back(-1);

		}

	}

	return ans;

}

int main() {

	int A[] = {5, 3, 6, 7, 2, 1, 4};
	int n = sizeof(A) / sizeof(int);

	vector<int> ans = fBruteForce(A, n);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}