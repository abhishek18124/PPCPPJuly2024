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
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 1e9;

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

	// e[] is not needed if you know for sure graph has no negative weight edges

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	minHeap.push({d[s], s});

	while (!minHeap.empty()) {

		auto [du, u] = minHeap.top();
		minHeap.pop();

		// if(e[u]) continue;

		if (d[u] < du) continue; // du is outdated

		for (auto [v, w] : adj[u]) {

			if (!e[v] and d[v] > du + w) {

				// edge b/w u and v is tensed, so we will relax

				d[v] = du + w;
				minHeap.push({d[v], v});

			}

		}

		e[u] = true; // node u is now explored

	}

	for (int i = 0; i < n; i++) {
		cout << "d[" << i << "] = " << d[i] << endl;
	}

	cout << endl;

	return 0;
}