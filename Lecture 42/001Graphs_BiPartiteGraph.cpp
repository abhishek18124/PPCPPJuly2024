/*

Given an undirected graph, check if it is bipartite or not.

	e.g.

	5 5

	0 1
	0 2
	1 3
	2 4
	3 4

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool dfs(int u, int c, const vector<vector<int>>& adj, vector<int>& cm) {

	// assign a color to node u

	cm[u] = c;

	for (int v : adj[u]) {

		if (cm[v] == -1) {

			// neighbour v of u is not yet colored / visited

			if (dfs(v, 1 - c, adj, cm) == false) { // sub-component of u is not bipartite therefore

				// component of u is not bipartite

				return false;

			}

		} else {

			// neighbour v of u is already colored / visted

			if (cm[u] == cm[v]) { // component of u is not bipartite

				return false;

			}

		}

	}

	return true; // component of u is bipartite

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

	vector<int> cm(n, -1);
	bool flag = true; // assume graph is bipartite

	for (int i = 0; i < n; i++) {

		if (cm[i] == -1) {

			// node i is not yet colored / visited, so make it the src and check if its component is bipartite or not

			if (dfs(i, 0, adj, cm) == false) {

				// graph is not biparitite
				flag = false;
				break;

			}

		}

	}

	if (flag) {

		cout << "biparite" << endl;

	} else {

		cout << "not biparite" << endl;

	}


	return 0;

}