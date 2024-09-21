#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcdef";

	cout << s.substr(2, 3) << endl;

	string substring = s.substr(1, 4);
	cout << substring << endl;

	cout << s.substr(4) << endl;

	cout << s.substr(1, 100) << endl;

	return 0;
}