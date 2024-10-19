#include<iostream>
#include<vector>

using namespace std;

int add1(int y) {
	return 1 + y;
}

int add2(int y) {
	return 2 + y;
}

int add3(int y) {
	return 3 + y;
}

int main() {

	vector<int> inp = {1, 2, 3, 4, 5};

	for (int i = 0; i < inp.size(); i++) {
		cout << inp[i] << " ";
	}

	cout << endl;

	vector<int> out(inp.size());

	transform(inp.begin(), inp.end(), out.begin(), add1);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	transform(inp.begin(), inp.end(), out.begin(), add2);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	transform(inp.begin(), inp.end(), out.begin(), add3);

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;



	return 0;
}