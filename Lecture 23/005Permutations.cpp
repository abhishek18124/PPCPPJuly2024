/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void f(char inp[], int n, int i) {

	// base case

	if (inp[i] == '\0') { // i == n
		cout << inp << endl;
		return;
	}

	// recursive case

	// f(i) = it is a fn that takes a sequence of decisions for positions i to n-1

	// or

	// f(i) = it is a fn that generates permutations for the inp[i...n-1]

	// decide for the ith position

	for (int j = i; j < n; j++) {

		// choose the jth option

		swap(inp[i], inp[j]);
		f(inp, n, i + 1);
		swap(inp[i], inp[j]); // backtracking

	}

}

int main() {

	char inp[] = "aabc";
	int n = strlen(inp);

	f(inp, n, 0);

	return 0;
}
