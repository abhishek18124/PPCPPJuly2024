/*

Given an directed graph do its topological sorting

	e.g.

	8 14

	0 1
	0 2
	0 3
	1 3
	1 4
	3 2
	3 4
	3 5
	3 6
	3 7
	4 6
	5 2
	6 7
	7 5

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> inDegMap(n, 0); // inDegMap[i] stores the inDeg. of node i
	for (int u = 0; u < n; u++) {
		for (int v : adj[u]) {
			// there is directed edge from u->v so inDeg of v inc. by 1
			inDegMap[v]++;
		}
	}

	queue<int> q; // init the queue with nodes whose inDeg is zero i.e. nodes that don't depend on other nodes
	for (int u = 0; u < n; u++) {
		if (inDegMap[u] == 0) {
			q.push(u);
		}
	}

	vector<int> ans; // to store topological sort

	while (!q.empty()) {

		int u = q.front(); q.pop();
		ans.push_back(u);

		for (int v : adj[u]) {

			inDegMap[v]--;
			if (inDegMap[v] == 0) {
				q.push(v);
			}

		}

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;

}