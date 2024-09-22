/*

	Constraints

	0 < m, n <= 10

	here, m denotes the no. of rows in the given 2D array
	      n denotes the no. of cols in the given 2D array

*/

#include<iostream>

using namespace std;

void printColumnWise(int arr[][10], int m, int n) {

	for (int j = 0; j < n; j++) {

		// print the jth column

		for (int i = 0; i < m; i++) {

			cout << arr[i][j] << " ";

		}

	}

}

int main() {

	int a[3][4];
	cout << "sizeof(a) = " << sizeof(a) << endl;

	char b[10][20];
	cout << "sizeof(b) = " << sizeof(b) << endl;

	double c[7][6];
	cout << "sizeof(c) = " << sizeof(c) << endl;

	bool d[2][4];
	cout << "sizeof(d) = " << sizeof(d) << endl;

	int arr[10][10];

	int m;
	cin >> m;

	int n;
	cin >> n;

	// read mxn values into the 2D array

	for (int i = 0 ; i < m; i++) {

		// read values in the ith row

		for (int j = 0; j < n; j++) {

			cin >> arr[i][j];

		}

	}

	// print mxn values of the 2D array

	for (int i = 0 ; i < m; i++) {

		// print values in the ith row

		for (int j = 0; j < n; j++) {

			cout  << arr[i][j] << " ";

		}

		cout << endl;

	}

	printColumnWise(arr, m, n);

	return 0;
}


