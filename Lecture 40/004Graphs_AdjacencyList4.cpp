/*

Implementation of the weighted graph using adjacency list.

Note : each vertex in the graph is generic.

*/

#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	map<char, vector<pair<char, int>>> adj;

	for (int i = 0; i < m; i++) {
		char u, v;
		cin >> u >> v;
		int w;
		cin >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // comment this out if graph is directed
	}

	for (pair<char, vector<pair<char, int>>> p : adj) {
		char u = p.first;
		vector<pair<char, int>> ngbs_u = p.second;
		cout << u << " : ";
		for (pair<char, int> pp : ngbs_u) {
			char ngb = pp.first;
			int wt = pp.second;
			cout << "(" << ngb << ", " << wt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	for (auto [u, ngbs_u] : adj) {
		cout << u << " : ";
		for (auto [ngb, wt] : ngbs_u) {
			cout << "(" << ngb << ", " << wt << ") ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}