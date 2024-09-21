#include<iostream>
#include<string>

using namespace std;

int main() {

	string s = "abc";
	string t = "def";

	cout << s + t << endl;
	cout << s << endl;
	cout << t << endl;

	s = s + t;

	cout << s << endl;
	cout << t << endl;

	string x = "hello";
	string y = "world";

	// x = x + y;
	x.append(y);

	cout << x << endl;

	string a = "codin";
	char ch = 'g';

	cout << a + ch << endl;

	cout << a + string(1, ch) << endl;

	string chString(5, ch);
	cout << a + chString << endl;

	string b = "hell";
	char ch2 = 'o';

	b.push_back(ch2);

	cout << b << endl;

	b.pop_back();

	cout << b << endl;

	return 0;
}