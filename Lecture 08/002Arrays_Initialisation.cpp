#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int A[5] = {10, 20, 30, 40, 50};
	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	int B[] = {100, 200, 300, 400};
	int m = sizeof(B) / sizeof(int);

	for (int i = 0; i < m; i++) {
		cout << B[i] << " ";
	}

	cout << endl;

	int C[5] = {1, 2};
	int o = sizeof(C) / sizeof(int);

	for (int i = 0; i < o; i++) {
		cout << C[i] << " ";
	}

	cout << endl;

	int D[5] = {};
	for (int i = 0; i < 5; i++) {
		cout << D[i] << " ";
	}
	cout << endl;

	int E[5] = {0};
	for (int i = 0; i < 5; i++) {
		cout << E[i] << " ";
	}
	cout << endl;

	int F[5];
	memset(F, 0, sizeof(F));
	for (int i = 0; i < 5; i++) {
		cout << F[i] << " ";
	}
	cout << endl;

	return 0;
}