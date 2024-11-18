// n <= 8

#include<iostream>

using namespace std;

void f(int n, char out[], int i, int openCnt, int closeCnt) {

	// base case

	if (i == 2 * n) { // openCnt == n and closeCnt == n
		out[i] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// f(i, openCnt, closeCnt) = it is a fn that decides for position i to 2n-1 such that so far we've used openCnt '(' and closeCnt ')'

	// decide the ith position

	// option 1 : use '('

	if (openCnt < n) {
		out[i] = '(';
		f(n, out, i + 1, openCnt + 1, closeCnt);
	}

	// optin 2 : use ')'

	if (closeCnt < openCnt) {
		out[i] = ')';
		f(n, out, i + 1, openCnt, closeCnt + 1);
	}

}


int main() {

	int n = 2;
	char out[20];

	f(n, out, 0, 0, 0);

	return 0;
}