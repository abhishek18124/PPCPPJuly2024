#include<iostream>
#include<cstring>

using namespace std;

int findLength(char str[]) { // char* str

	int cnt = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		cnt++;
	}

	return cnt;

}

int main() {

	char str[] = "today is 15th sept";

	cout << findLength(str) << endl;

	cout << strlen(str) << endl;

	return 0;
}