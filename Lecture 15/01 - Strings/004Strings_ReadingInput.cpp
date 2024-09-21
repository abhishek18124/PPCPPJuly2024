#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main() {

	string s;

	// cin >> s; // leading whitespaces are ignored, and we stop reading when we encounter non-leading whitespaces
	// getline(cin, s); // leading whitespace are not ignored, and it stops reading as soon as it encounter newline (default delimiter)
	// getline(cin, s, '$');
	getline(cin >> ws, s, '$');

	cout << s << endl;

	return 0;
}