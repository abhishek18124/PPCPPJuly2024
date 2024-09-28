#include<iostream>

using namespace std;

void read(int** ptr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ptr[i][j];
		}
	}
}

void print(int** ptr, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printArr(int arr[][3], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printArr2(int (*arr)[3], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {

	int m, n;
	cin >> m >> n;

	int** ptr = new int*[m];

	for (int i = 0; i < m; i++) {
		ptr[i] = new int[n];
	}

	read(ptr, m, n);

	print(ptr, m, n);

	for (int i = 0; i < m; i++) {
		delete [] ptr[i];
	}

	delete [] ptr;

	int arr[2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};

	printArr(arr, 2, 3);

	printArr2(arr, 2, 3);


	return 0;
}