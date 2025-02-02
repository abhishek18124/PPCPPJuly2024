/*

Snake and Ladders Game

*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> getPath(int u, const vector<int>& pm) {

	vector<int> path = {u};

	while (pm[u] != -1) {
		u = pm[u];
		path.push_back(u);
	}

	reverse(path.begin(), path.end());

	return path;

}

int minDiceThrows(int n,
                  const vector<pair<int, int>>& snakes,
                  const vector<pair<int, int>>& ladders) {

	vector<int> bm(n + 1, 0);

	for (auto [startPos, endPos] : snakes) {
		bm[startPos] = endPos - startPos;
	}

	// for (pair<int ,int> ladderPos: ladders) {
	// 	int startPos = ladderPos.first;
	// 	int endPos = ladderPos.second;
	// 	bm[startPos] = endPos - startPos;
	// }

	for (auto [startPos, endPos] : ladders) {
		bm[startPos] = endPos - startPos;
	}

	vector<vector<int>> adj(n + 1); // nodes are numbered from 1 to n
	for (int u = 1; u < n; u++) {

		if (bm[u] != 0) continue; // a snake or ladder starts on cell u

		// roll the die on cell u

		for (int d = 1; d <= 6; d++) {
			int v = u + d;
			if (v <= n) { // to avoid going outside the board
				v = v + bm[v];
				adj[u].push_back(v); // add a dir. edge from u to v
			}

		}

	}

	queue<int> q;
	q.push(1);

	vector<bool> vis(n + 1, false);
	vis[1] = true;

	vector<int> d(n + 1);
	d[1] = 0;

	vector<int> pm(n);
	pm[1] = -1;

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

	vector<int> path = getPath(n, pm);
	for (int i = 0; i < path.size(); i++) {
		cout << path[i] << " ";
	}
	cout << endl;

	return d[n];

}

int main() {

	int n = 36;

	vector<pair<int, int>> snakes  = {
		{17, 4},
		{20, 6},
		{24, 16},
		{32, 30},
		{34, 12}
	};

	vector<pair<int, int>> ladders = {
		{2, 15},
		{5, 7},
		{9, 27},
		{18, 29},
		{25, 35}
	};

	cout << minDiceThrows(n, snakes, ladders) << endl;

	return 0;
}