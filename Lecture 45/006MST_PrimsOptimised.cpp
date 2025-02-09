/*

prims algorithm

e.g.

input :

7 9

1 2 4
1 3 5
2 4 2
2 5 7
3 4 6
3 6 9
5 6 1
5 7 3
6 7 8

output :

22

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n + 1); // 1-based node numbering is done
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector inMst(n + 1, false);

	// time : O(ElogV)

	set<pair<int, int>> minHeap;
	minHeap.insert({0, 1}); // you don't incur any cost to start from node 1

	vector<int> bestEdgeWgtToReach(n + 1, INF);
	bestEdgeWgtToReach[1] = 0; // since we don't incur any cost to start from node 1

	int mstSum = 0;

	while (!minHeap.empty()) {

		cout << ".";

		auto [du, u] = *minHeap.begin();
		minHeap.erase(minHeap.begin());

		if (inMst[u]) continue;

		// add u to mst

		mstSum += du;
		inMst[u] = true;

		for (auto [v, w] : adj[u]) {
			if (!inMst[v] and w < bestEdgeWgtToReach[v]) {
				minHeap.erase({bestEdgeWgtToReach[v], v});
				bestEdgeWgtToReach[v] = w;
				// minHeap.insert({bestEdgeWgtToReach[v], v});
				minHeap.insert({w, v});
			}
		}

	}

	cout << mstSum << endl;

	return 0;
}