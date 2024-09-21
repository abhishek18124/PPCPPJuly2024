#include<iostream>
#include<string>

using namespace std;

int main() {

	int x = 10;
	int y;
	y = x;

	int z = x;

	cout << y << endl;
	cout << z << endl;

	string s = "abc";
	string t;
	t = s; // we used copy assignment operator to create t as a copy of s
	cout << t << endl;

	string a = s; // we used copy constructor to create a as a copy of s
	cout << a << endl;


	return 0;
}