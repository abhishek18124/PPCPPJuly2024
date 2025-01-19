/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is int.

*/

#include<iostream>
#include<set>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<set<int>> adj(n);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; // we are using 0-based labelling for nodes
		adj[u].insert(v);
		adj[v].insert(u); // comment if graph is directed
	}

	for (int i = 0; i < n; i++) {
		cout << i << " : ";
		for (int ngb : adj[i]) {
			cout << ngb << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}