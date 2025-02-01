/*

Given an directed graph, check if there exists a back-edge or not.

	e.g.

	4 4

	0 1
	1 2
	2 3
	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

bool dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& stackState) {

	vis[u] = true;
	stackState[u] = true;

	for (int v : adj[u]) {

		if (!vis[v]) { // neighbour v of u is not yet visited

			if (dfs(v, adj, vis, stackState)) {

				// backedge detected in the sub-component of u

				// therefore backedge found in the component of u

				return true;

			}

		} else { // neighbour v of u is visited

			// check if u->v is a backedge or not

			// check if there is a dir. path from v to u

			if (stackState[v]) {

				// u->v is backedge

				return true;

			}

		}

	}

	stackState[u] = false;

	return false; // no backedge found in the component of u

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		// adj[v].push_back(u); // since graph is directed
	}

	bool flag = false; // assume no dir. cycle is present in the graph
	vector<bool> vis(n, false); // vis[i] indicates if node i is visited or not
	vector<bool> stackState(n, false); // statckState[i] indicates if node i is present on the function call stk or not

	for (int i = 0; i < n; i++) {

		if (!vis[i]) {

			// check if a directed cycle is present in the component of node i

			if (dfs(i, adj, vis, stackState)) {
				flag = true;
				break;
			}

		}

	}

	if (flag) {
		cout << "directed cycle found" << endl;
	} else {
		cout << "no directed cycle found" << endl;
	}


	return 0;

}