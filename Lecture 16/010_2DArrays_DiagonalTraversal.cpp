/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>

using namespace std;

void printDiagonal(int mat[][10], int m, int n, int i, int j) {

	// print the diagonal that starts at the i,jth index

	int dlen = min(m - i, n - j);

	for (int k = 0; k < dlen; k++) {

		cout << mat[i + k][j + k] << " ";

	}

	cout << endl;

}

void diagonalTraversal(int mat[][10], int m, int n) {

	// iterate over diagonal starting points

	// 1. (i, 0)

	for (int i = 0; i <= m - 1; i++) {

		printDiagonal(mat, m, n, i, 0);

	}

	// 2. (0, j)

	for (int j = 1; j <= n - 1; j++) {

		printDiagonal(mat, m, n, 0, j);

	}

}

int main() {

	int mat[10][10] = {
		{11, 12, 13, 14},
		{15, 16, 17, 18},
		{19, 20, 21, 22}
	};

	int m = 3;
	int n = 4;

	diagonalTraversal(mat, m, n);

	return 0;
}