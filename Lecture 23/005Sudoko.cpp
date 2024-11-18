/*

Sudoku

Given a partially filled 'n x n' grid, the goal is to assign digits from 1 to 9 to the empty cells
so that every row, column, and subgrid of size '√n x √n'  contains exactly one instance of
the digits from 1 to 9.

Assume 'n' is a perfect square, hence there are 'n' subgrids of size '√n x √n' each.


*/

#include<iostream>
#include<cmath>

using namespace std;

bool isValid(int grid[][9], int n, int i, int j, int d) {

	for (int k = 0; k < n; k++) {
		if (grid[i][k] == d || grid[k][j] == d) {
			return false;
		}
	}

	// digit 'd' is not is the same row or coln but it can be in the same subgrid of the (i, j)th cell

	// check if 'd' is in the subgrid of the (i, j)th cell ?

	int rn = sqrt(n);

	int sx = i - (i % rn);
	int sy = j - (j % rn);

	for (int x = sx; x < sx + rn; x++) {
		for (int y = sy; y < sy + rn; y++) {
			if (grid[x][y] == d) {
				return false;
			}
		}
	}

	return true; // d is a valid digit i.e. it can be assigned to the i,jth cell of the grid

}

void solveSudoku(int grid[][9], int n, int i, int j) {

	// base case
	if (i == n) {
		// all empty cells have been assigned valid digits
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	// recursive case

	if (j == n) {
		// digits have been assigned to all the cells in the ith row -
		// move to the next row, and start filling from its 0th cell
		solveSudoku(grid, n, i + 1, 0);
		return;
	}

	if (grid[i][j] != 0) {
		// (i, j)th cell is already assigned a digit -
		// move to the next cell at the (i, j+1)th idx
		solveSudoku(grid, n, i, j + 1);
		return;
	}

	// assign a valid digit 'd' to the (i, j)th cell where 1<=d<=9
	for (int d = 1; d <= 9; d++) {
		if (isValid(grid, n, i, j, d)) {
			grid[i][j] = d;
			solveSudoku(grid, n, i, j + 1);
			grid[i][j] = 0; // backtracking
		}
	}

}

int main() {

	int n = 9;
	int grid[][9] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	solveSudoku(grid, n, 0, 0);

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << grid[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	return 0;
}