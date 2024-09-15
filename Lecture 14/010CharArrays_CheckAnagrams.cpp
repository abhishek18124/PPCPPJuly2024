#include<iostream>

using namespace std;

// no. of steps = n (to build f1[]) + n(to build f2[]) + 26 (to cmp f1[] and f2[])

bool isAnagram(char s1[], char s2[]) {

	// 1. build a freqMap for s1[]

	int f1[26] = {0};
	for (int i = 0; s1[i] != '\0'; i++) {
		char ch = s1[i];
		int idx = ch - 'a';
		f1[idx]++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << f1[i] << " ";
	// }

	// cout << endl;

	// 2. build a freqMap for s2[]

	int f2[26] = {0};
	for (int i = 0; s2[i] != '\0'; i++) {
		f2[s2[i] - 'a']++;
	}

	// for (int i = 0; i < 26; i++) {
	// 	cout << f2[i] << " ";
	// }

	// cout << endl;

	for (int i = 0; i < 26; i++) {
		if (f1[i] != f2[i]) {
			// s1[] and s2[] are not anagrams
			return false;
		}
	}

	// s1[] and s2[] are anagrams
	return true;

}

int main() {

	char s1[] = "state";
	char s2[] = "taste";

	isAnagram(s1, s2) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}