#include<iostream>
#include<vector>

using namespace std;

void generateCombinations(int t, const vector<int>& c, vector<int>& comb, int i) {

	// base case

	if (t == 0) {
		for (int x : comb) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	// recursion case

	// generate the combinations of c[i...n-1] that sum up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	for (int j = i; j < c.size(); j++) {

		if (c[j] <= t) {

			comb.push_back(c[j]);
			generateCombinations(t - c[j], c, comb, j);
			comb.pop_back(); // backtracking

		}

	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> comb; // to track the combination that sums up to 't'

	generateCombinations(t, c, comb, 0);

	return 0;
}