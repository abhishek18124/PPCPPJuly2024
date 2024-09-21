#include<iostream>
#include<string>

using namespace std;

// time : O(n)

bool isGoodString(const string& str) {

	for (int i = 0; str[i] != '\0'; i++) {

		char ch = str[i];
		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

			// ch is a consonant
			return false; // str is not a good string

		}

	}

	return true; // str is a good string

}

bool isGoodString2(const string& str) {

	for (char ch : str) {

		if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) {

			// ch is a consonant
			return false; // str is not a good string

		}

	}

	return true; // str is a good string

}

int main() {

	string str = "uoiea";

	isGoodString(str) ? cout << "good string" << endl :
	                         cout << "not good string" << endl;

	isGoodString2(str) ? cout << "good string" << endl :
	                          cout << "not good string" << endl;

	return 0;
}