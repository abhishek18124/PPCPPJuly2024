#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	double ans = 0;

	while (ans * ans <= n) {
		ans = ans + 1;
	}

	ans = ans - 1;

	while (ans * ans <= n) {
		ans = ans + 0.1;
	}

	ans = ans - 0.1;

	while (ans * ans <= n) {
		ans = ans + 0.01;
	}

	ans = ans - 0.01;

	while (ans * ans <= n) {
		ans = ans + 0.001;
	}

	ans = ans - 0.001;

	cout << ans << endl;

	return 0;
}