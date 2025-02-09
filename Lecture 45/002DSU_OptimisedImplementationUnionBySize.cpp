/*

optimising union and find operations using

* union by rank
* path compression

*/

#include<iostream>
#include<vector>

using namespace std;

class disjointSet {

public:

	vector<int> p;
	vector<int> s;

	disjointSet(int n) {
		p.resize(n + 1);
		s.resize(n + 1);
	}

	void createSet(int x) {
		p[x] = x;
		s[x] = 1;
	}

	void unionSet(int x, int y) { // union by rank

		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (s[lx] > s[ly]) {
				p[ly] = lx;
				s[lx] += s[ly];
			} else {
				p[lx] = ly;
				s[ly] += s[lx];
			}

		}

	}

	int findSet(int x) {
		if (p[x] == x) {
			return x;
		}

		return p[x] = findSet(p[x]); // path compression
	}

};

int main() {

	int n = 4;

	disjointSet ds(n);

	ds.createSet(1);
	ds.createSet(2);
	ds.createSet(3);
	ds.createSet(4);

	ds.unionSet(2, 3);

	cout << ds.findSet(3) << endl;
	cout << ds.findSet(2) << endl;

	ds.unionSet(1, 4);

	cout << ds.findSet(4) << endl;

	ds.unionSet(3, 4);

	cout << ds.findSet(1) << endl;
	cout << ds.findSet(2) << endl;
	cout << ds.findSet(3) << endl;
	cout << ds.findSet(4) << endl;

	return 0;

}