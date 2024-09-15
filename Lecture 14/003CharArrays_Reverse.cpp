#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverseString(char str[]) {

	int n = strlen(str);

	int i = 0;
	int j = n - 1;

	while (i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}

}

int main() {

	char str[] = "abcde";

	cout << str << endl;

	// reverseString(str);

	// strrev(str) // part of cstring

	// reverse(begin, end); // [begin, end)

	int n = strlen(str);

	reverse(str, str + n); // reverses str[0...n) i.e. str[0...n-1]

	cout << str << endl;

	return 0;
}