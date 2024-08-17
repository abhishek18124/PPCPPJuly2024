#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	n > 0 ? cout << "+ve" << endl :
	             n < 0 ? cout << "-ve" << endl : cout << "zero" << endl;

	return 0;
}