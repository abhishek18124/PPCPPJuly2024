/*

Computing SSSP using the BFS algorithm in an unweighted graph.

note : each vertex in the graph is an integer in the range [0, n-1].

e.g.

	9 12

	0  1
	0  2
	1  3
	1  4
	2  4
	2  5
	3  6
	4  6
	4  7
	5  7
	6  8
	7  8

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 1e9;

vector<int> getPath(int u, const vector<int>& pm) {

	vector<int> path = {u};

	while (pm[u] != -1) {
		u = pm[u];
		path.push_back(u);
	}

	reverse(path.begin(), path.end());

	return path;

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

	queue<int> q;
	q.push(0);

	vector<bool> vis(n, false);
	vis[0] = true;

	vector<int> d(n, INF);
	d[0] = 0;

	vector<int> pm(n);
	pm[0] = -1;

	while (!q.empty()) {

		int u = q.front(); q.pop();

		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
				d[v] = d[u] + 1;
				pm[v] = u;
			}
		}

	}

	for (int u = 0; u < n; u++) {
		cout << "d[" << u << "] = " << d[u] << endl;
	}

	cout << endl << endl;


	for (int u = 0; u < n; u++) {
		cout << "pm[" << u << "] = " << pm[u] << endl;
	}

	cout << endl;

	vector<int> path = getPath(5, pm); // 8 is dst

	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}

	cout << endl;

	return 0;
}