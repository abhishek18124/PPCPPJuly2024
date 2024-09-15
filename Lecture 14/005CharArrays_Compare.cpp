#include<iostream>
#include<cstring>

using namespace std;

// len(s1) = m
// len(s2) = n
// #iterations = min(m, n)

int compareString(char s1[], char s2[]) {

	int i = 0;
	int j = 0;

	while (s1[i] != '\0' and s2[j] != '\0') {

		if (s1[i] > s2[j]) {

			// s1 > s2

			return 1;

		}

		if (s1[i] < s2[j]) {

			// s1 < s2

			return -1;

		}

		// s1[i] is equal to s2[j]

		i++;
		j++;

	}

	if (s1[i] != '\0') {

		// length of s1 > length s2 therefore s1 > s2

		return 1;

	} else if (s2[j] != '\0') {

		// length of s1 < length s2 therefore s1 < s2

		return -1;

	}

	// length of s1 is equal to length of s2

	return 0;


}

int main() {

	char s1[] = "zzaz";
	char s2[] = "zazzzz";

	int ans = compareString(s1, s2);
	// int ans = strcmp(s1, s2);

	if (ans > 0) {
		cout << s1 << " > " << s2 << endl;
	} else if (ans < 0) {
		cout << s1 << " < " << s2 << endl;
	} else {
		cout << s1 << " is equal to " << s2 << endl;
	}

	return 0;
}