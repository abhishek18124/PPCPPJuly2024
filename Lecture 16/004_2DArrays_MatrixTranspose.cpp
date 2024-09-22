/*

	Constraints :

	0 < n <= 10

*/

#include<iostream>

using namespace std;

// steps = (n^2 - n) / 2 each step takes const time
// time : O(n^2)

void transpose(int mat[][10], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = i + 1; j < n; j++) {

			swap(mat[i][j], mat[j][i]);

		}

	}

}

int main() {

	int n;
	cin >> n;

	int mat[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	cout << "matrix before transpose = " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	transpose(mat, n);

	cout << "matrix after transpose = " << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}