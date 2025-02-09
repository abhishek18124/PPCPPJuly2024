/*

kruskals algorithm using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class disjointSet {

public:

	vector<int> p;
	vector<int> r;

	disjointSet(int n) {
		p.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			p[i] = i;
		}
		r.resize(n + 1, 0);
	}

	void createSet(int x) {
		p[x] = x;
		r[x] = 0;
	}

	void unionSet(int x, int y) { // union by rank

		int lx = findSet(x);
		int ly = findSet(y);

		if (lx != ly) {

			if (r[lx] == r[ly]) {
				r[lx]++;
			}

			if (r[lx] > r[ly]) {
				p[ly] = lx;
			} else {
				p[lx] = ly;
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

class edge {
public:
	int u, v, w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

// return true if you want a to be ordered before b otherwise return false

bool edgeCmp(edge a, edge b) {
	if (a.w < b.w) {
		return true;
	}
	return false;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
	}

	// time : O(ElogE)

	sort(edges.begin(), edges.end(), edgeCmp); // ElogE

	disjointSet ds(n);

	int mstSum = 0;
	vector<edge> ans;

	for (auto e : edges) { // E
		int u = e.u;
		int v = e.v;
		int w = e.w;
		if (ds.findSet(u) != ds.findSet(v)) {
			// uv is safe edge
			// include uv in the mst
			mstSum += w;
			ds.unionSet(u, v);
			ans.push_back(e);
			if (ans.size() == n - 1) break;
		}
	}

	for (auto e : ans) {
		cout << e.u << " " << e.v << endl;
	}

	cout << mstSum << endl;

	return 0;
}