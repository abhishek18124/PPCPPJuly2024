#include<iostream>

using namespace std;

int main() {

	// int p, r, t;
	// cin >> p >> r >> t;

	int p;
	cin >> p;

	int r;
	cin >> r;

	int t;
	cin >> t;

	cout << (p * r * t) / 100 << endl; // exp : 1.5 act : 1
	cout << (p * r * t) / 100.0 << endl;
	cout << (p * r * t) / (float)100 << endl;
	cout << ((float)p * r * t) / 100 << endl;

	double si = (p * r * t) / 100.0;
	cout << si << endl;

	return 0;
}