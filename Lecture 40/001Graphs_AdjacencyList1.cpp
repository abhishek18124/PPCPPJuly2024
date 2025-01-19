/*

Implementation of the graph using adjacency list.

Note : each vertex in the graph is an integer.

*/

#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	// n is no. of nodes (labelled 0 to n-1)
	// m is no. of edges

	vector<vector<int>> adj(n);

	for (int i = 0; i < m; i++) {

		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);

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