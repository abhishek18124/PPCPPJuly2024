#include<iostream>

using namespace std;

int main() {

	char ch = 'A';
	int* ptr2 = (int*)&ch;
	cout << ptr2 << endl;

	return 0;
}