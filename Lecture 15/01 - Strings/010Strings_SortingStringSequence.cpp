#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// return true if you want a to be ordered before b otherwise return false

bool myLenCmp(string a, string b) {

	if (a.size() < b.size()) {

		// since we sorting in inc. ordere based on string length, we want a to be ordered before b when a.size() is less than b.size()
		return true;

	}

	return false;

}

int main() {

	string arr[] = {"abcd", "z", "ef", "xyz"};
	int n = 4;

	sort(arr, arr + n, myLenCmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}