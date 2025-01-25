/*

Implementation of graph traversal using

	1. depth first search (dfs)
	2. breadth first search (bfs)

	e.g.

	16 16

	0 2
	0 3
	1 3
	1 4
	2 5
	3 5
	3 6
	4 6

	7 9
	8 9
	9 10
	9 11

	12 13
	12 14
	13 15
	14 15

*/

#include<iostream>
#include<vector>

using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis) {

	vis[u] = true;

	cout << u << " ";

	for (int v : adj[u]) {
		if (!vis[v]) {
			dfs(v, adj, vis);
		}
	}

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<bool> vis(n, false);
	int cnt = 0; // to track no. of components in the graph

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// traverse the component in which node i is present
			// using dfs or bfs with node i as the src

			dfs(i, adj, vis);
			cout << endl;
			cnt++;

		}

	}

	cout << "#components = " << cnt << endl;

	return 0;
}