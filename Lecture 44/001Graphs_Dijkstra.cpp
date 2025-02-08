/*

note : nodes are numbered from 0 to n - 1

dijkstra's algorithm

e.g.

input :

5 7
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
3 4 8

output :

0 8 5 9 7

*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

const int INF = 1e9;

vector<int> getPath(int u, vector<int>& p) {

	// this fn finds the path from src to node u using the shortest path tree which encoded using the parentMap p[]

	vector<int> path = {u};
	while (p[u] != -1) {
		u = p[u];
		path.push_back(u);
	}

	reverse(path.begin(), path.end());
	return path;

}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w}); // since i/p graph is undirected
	}

	int s = 0; // assume node 0 to be the src vertex

	vector<int> d(n, INF);
	d[s] = 0;

	vector<bool> e(n, false); // e[i] indicates if node 'i' is explored or not

	set<pair<int, int>> minHeap;
	// for(int i=0; i<n; i++) {
	// 	minHeap.insert({d[i], i});
	// }
	minHeap.insert({d[s], s});

	vector<int> p(n, -1);

	while (!minHeap.empty()) {

		auto [du, u] = *minHeap.begin();
		minHeap.erase(minHeap.begin());
		// minHeap.erase({du, u});

		for (auto [v, w] : adj[u]) {

			if (!e[v] and d[v] > du + w) {

				// edge b/w u and v is tensed, so we will relax

				minHeap.erase({d[v], v});
				d[v] = du + w;
				minHeap.insert({d[v], v});

				p[v] = u;

			}

		}

		e[u] = true; // node u is now explored

	}

	// for (int i = 0; i < n; i++) {
	// 	cout << "d[" << i << "] = " << d[i] << endl;
	// }

	// cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "p[" << i << "] = " << p[i] << endl;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "d[" << i << "] = " << d[i] << " : ";
		vector<int> path = getPath(i, p);
		for (auto x : path) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}