/*

cycle detection in an undirected graph using disjoint set

note : nodes are numbered from 1 to n

e.g.

input :

4 4

1 2
2 3
3 4
4 1

output :

true

*/

#include<iostream>
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
	int u, v;
	edge(int u, int v) {
		this->u = u;
		this->v = v;
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edges.push_back(edge(u, v));
	}

	disjointSet ds(n); // createSet() is handled in the constructor itself

	// for(int i=1; i<=n; i++) {
	// 	ds.createSet(i);
	// }

	bool flag = false; // assume no cycle is present

	for (auto e : edges) {
		int u = e.u; int v = e.v;
		if (ds.findSet(u) == ds.findSet(v)) {
			// since u and v are in the same set i.e. same component
			// it means there already is a path b/w them and now
			// we've an edge b/w them so graph has cycle
			flag = true;
			break;
		} else {
			ds.unionSet(u, v);
		}
	}

	if (flag) {
		cout << "cycle found" << endl;
	} else {
		cout << "no cycle found" << endl;
	}

	return 0;
}