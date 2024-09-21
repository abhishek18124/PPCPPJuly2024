#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abcabcdef";

	cout << s.find("abc") << endl;
	cout << s.rfind("abc") << endl;
	cout << s.find("def") << endl;
	cout << s.find("xyz") << endl;
	cout << string::npos << endl; // this is the highest value of size_t

	if (s.find("xyz") == string::npos) {
		cout << "xyz is not present" << endl;
	}

	return 0;
}