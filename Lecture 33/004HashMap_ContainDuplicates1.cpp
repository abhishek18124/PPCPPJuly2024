// constraints

// n <= 10^6
// -10^9 <= arr[i] <= 10^9

#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

// time : O(nlogn) since we are using a map<>
// time : on avg. O(n) if we use unordered_map<>
// space: O(n) due to map<> if all the elements in v[] are distinct

bool isDuplicatePresent(const vector<int>& v) {

	map<int, int> freqMap;

	for (int x : v) {

		freqMap[x]++;

	}

	for (pair<int, int> p : freqMap) {
		// cout << p.first << " " << p.second << endl;
		int el = p.first;
		int fr = p.second;
		cout << el << " : " << fr << endl;
	}

	// for (auto& [el, fr] : freqMap) {
	// 	cout << el << " : " << fr << endl;
	// }

	for (pair<int, int> p : freqMap) {
		int el = p.first;
		int fr = p.second;
		if (fr > 1) {
			// you've found a duplicate
			return true;
		}
	}

	return false; // no duplicates found

}

// time : O(nlogn) since we are using a set<>
// time : on avg. O(n) if we use unordered_set<>
// space: O(n) due to set<> if all the elements in v[] are distinct

bool isDuplicatePresentUsingSet(const vector<int>& v) {

	set<int> s;

	for (int x : v) {
		if (s.find(x) == s.end()) {
			// x is not yet present
			s.insert(x);
		} else {
			// x is already present, i.e. you've found a duplicate
			return true;
		}
	}

	return false; // no duplicates found


}

int main() {

	vector<int> v = {1, 2, 3, 1};

	isDuplicatePresent(v) ? cout << "true" << endl : cout << "false" << endl;
	isDuplicatePresentUsingSet(v) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}