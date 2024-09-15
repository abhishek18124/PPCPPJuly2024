#include<iostream>

using namespace std;

int main() {

	char str1[] = {'a', 'b', 'c', 'd', 'e', '\0'};
	cout << str1 << endl;

	char str2[] = "hello";
	cout << str2 << endl;

	cout << str2[0] << " ";
	cout << str2[1] << " ";
	cout << str2[2] << " ";
	cout << str2[3] << " ";
	cout << str2[4] << " " << endl;

	for (int i = 0; str2[i] != '\0'; i++) {
		cout << str2[i] << endl;
	}

	cout << endl;

	return 0;

}