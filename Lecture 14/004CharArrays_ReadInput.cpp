// n <= 100

#include<iostream>

using namespace std;

void readString(char str[], char dlim = '\n') {

	int j = 0;
	char ch;

	while (true) {

		ch = cin.get();
		if (ch == dlim) { // '\n' is a.k.a delimiting char
			break;
		}
		str[j] = ch;
		j++;

	}

	str[j] = '\0';

}

int main() {

	char str[101]; // based on constraints

	// cin >> str; // cin >> stops reading the i/p as soon as it encounters non-leading whitespace character, leading whitespaces are ignored

	// readString(str, '$');

	// cin.getline(str, 101, '$');
	// cin.getline(str, 101, '\n'); // '\n' is the default delimiting character
	cin.getline(str, 5, '$');

	cout << str << endl;

	return 0;
}