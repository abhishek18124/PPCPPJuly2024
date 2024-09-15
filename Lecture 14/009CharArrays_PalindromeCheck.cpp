#include<iostream>
#include<cstring>

using namespace std;

bool isPalindrome(char str[]) { // n/2 steps // space : O(1)

	int n = strlen(str);

	int i = 0;
	int j = n - 1;

	while (i < j) {

		if (str[i] != str[j]) {

			// str[] is not a palindrome

			return false;

		}

		i++;
		j--;

	}

	// str[] is a palindrome

	return true;

}

int main() {

	char str[] = "abccba";

	isPalindrome(str) ? cout << "true" << endl : cout << "false" << endl;

	return 0;

}