#include<iostream>
#include<string>

using namespace std;

// time : O(n)
// [HW] build answer string in addition to finding its length

int longestGoodSubstringOptimised(const string& str) {

	int cnt = 0;
	int maxSoFar = 0;

	for (char ch : str) {

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {

			cnt++;
			maxSoFar = max(maxSoFar, cnt);

		} else {

			// ch is a consonant

			cnt = 0;

		}

	}

	return maxSoFar;

}

int main() {

	string str = "cbaeicdeiou";

	cout << longestGoodSubstringOptimised(str) << endl;

	return 0;
}