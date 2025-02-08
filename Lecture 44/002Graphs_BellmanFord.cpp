/*

note : nodes are numbered from 0 to n - 1

bellman-ford's algorithm

e.g.

input :

5 7
0 1 2
0 2 5
1 2 1
1 3 6
1 4 4
2 4 1
4 3 1

output :

0 2 3 5 4

*/

#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e9;

class edge {
public:
	int u, v, w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edges; // a 3-sized vector<int> can also be used to represent weighted edge

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
		// edges.push_back(edge(v, u, w)); // uncomment for undirected graph
	}

	int s = 0; // assume node 0 to be the src vertex

	vector<int> d(n, INF);
	d[s] = 0;

	for (int j = 1; j <= n - 1; j++) {

		for (auto e : edges) {
			// e.u -> e.v e.w
			if (d[e.v] > d[e.u] + e.w) {
				// edge from u to v is tensed
				d[e.v] = d[e.u] + e.w; // relax the edge
			}
		}

	}

	for (int i = 0; i < n; i++) {
		cout << "d[" << i << "] = " << d[i] << endl;
	}


	return 0;
}