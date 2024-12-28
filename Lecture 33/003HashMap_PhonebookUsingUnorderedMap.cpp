/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main() {

	map<string, vector<string>> phoneMap;

	phoneMap["Aditya"].push_back("0000");
	phoneMap["Aditya"].push_back("1111");
	phoneMap["Aditya"].push_back("2222");

	phoneMap["Yukta"].push_back("1234");
	phoneMap["Yukta"].push_back("5678");

	phoneMap["Aryan"].push_back("9876");

	for (pair<string, vector<string>> contact : phoneMap) {

		string contactName = contact.first;
		vector<string> phoneNums = contact.second;

		cout << contactName << " : ";
		for (string num : phoneNums) {
			cout << num << " ";
		}

		cout << endl;

	}

	return 0;
}