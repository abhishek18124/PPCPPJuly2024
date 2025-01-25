/*

Given an undirected graph, check if there exists a cycle or not.

	e.g.

	3 3

	0 1
	0 2
	1 2

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int u, int p, const vector<vector<int>>& adj, vector<bool>& vis) {

	vis[u] = true;

	for (int v : adj[u]) {

		if (!vis[v]) {

			// ngb v is not yet visited

			if (dfs(v, u, adj, vis)) {

				// you've found a cycle in the sub-component of v
				// therefore you've found a cycle in the component
				// of u

				return true;

			}

		} else {

			// ngb v is visited

			// check if u-v is a backedge ?

			if (v != p) {

				// u-v is a backedge therefore you've cycle in the component of u

				return true;

			}

		}

	}

	// no cycle found in the component of u

	return false;

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
	bool flag = false; // assume there is no cycle in the graph

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// check if there is a cycle in the component of node i
			// using dfs with node i as the src

			if (dfs(i, -1, adj, vis)) {

				// you've found a cycle in the component of node i
				// therefore you've found a cycle in the graph

				flag = true;
				break;

			}

		}

	}

	flag ? cout << "cycle found" << endl : cout << "no cycle found" << endl;


	return 0;
}