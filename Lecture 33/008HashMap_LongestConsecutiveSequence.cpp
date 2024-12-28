/*
	https://leetcode.com/problems/longest-consecutive-sequence/
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:

	// time : on avg. O(n)

	int longestConsecutive(vector<int>& nums) {

		unordered_map<int, bool> startMap;

		for (int x :  nums) { // on. avg. O(n)

			if (startMap.find(x - 1) == startMap.end()) {
				startMap[x] = true; // since we've not seen x-1 so far, we can make x as a starting point for now
			} else {
				// you've seen x-1 previously so x cannot be the starting point
				startMap[x] = false;
			}

			if (startMap.find(x + 1) != startMap.end()) {
				// x+1 was seen previously
				startMap[x + 1] = false; // since we've x, x+1 can no longer be a starting point
			}

		}


		// for (pair<int, bool> p : startMap) {
		// 	cout << p.first << " : " << p.second << endl;
		// }

		int maxSoFar = 0;

		for (pair<int, bool> p : startMap) { // on avg. O(n)
			int el = p.first;
			bool canStart = p.second;
			if (canStart) {
				// find the length of the sequence of consecutive elements
				// that starts with 'el'
				int cnt = 0;
				while (startMap.find(el) != startMap.end()) {
					cnt++;
					el++;
				}

				maxSoFar = max(maxSoFar, cnt);
			}
		}

		return maxSoFar;

	}
};

int main() {

	Solution s;

	vector<int> nums = {4, 2, 1, 3, 7, 5, 9, 8, 12, 15, 13, 14};

	cout << s.longestConsecutive(nums) << endl;

}
