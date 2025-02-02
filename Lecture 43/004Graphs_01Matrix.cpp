// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// 1. brute-force approach - time : O(m^2.n^2)

vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				for (int ii = 0; ii < m; ii++) {
					for (int jj = 0; jj < n; jj++) {
						dist[ii][jj] = min(dist[ii][jj], abs(ii - i) + abs(jj - j));
					}
				}
			}
		}
	}

	return dist;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> dist = updateMatrix(mat);

	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}