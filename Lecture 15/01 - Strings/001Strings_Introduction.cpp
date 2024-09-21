
#include<iostream>
#include<string>

using namespace std;

int main() {

	string s1; // declaration
	s1 = "hello"; // assignment // '\0' is added automatically
	cout << s1 << endl;
	cout << s1.size() << " " << s1.length() << endl;

	string s2 = "coding blocks";
	cout << s2 << endl;
	cout << s2.size() << " " << s2.length() << endl;

	int n = s2.size();
	cout << s2[0] << " " << s2.front() << endl;
	cout << s2[n - 1]  << " " << s2.back() << endl;

	for (int i = 0; s2[i] != '\0'; i++) {
		cout << s2[i] << " ";
	}
	cout << endl;

	return 0;
}