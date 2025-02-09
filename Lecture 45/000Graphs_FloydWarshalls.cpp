/*

note : nodes are numbered from 1 to n

floyd-warshall's algorithm

e.g.

input :

4 5
1 2 8
1 3 1
1 4 5
2 4 2
3 4 3

output :

0 6	1 4
6 0	5 2
1 5	0 3
4 2	3 0

*/

#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e9;

class edge {
public:
	int u, v, w;
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

int main() {

	int n, m;
	cin >> n >> m;

	vector<edge> edges; // a 3-sized vector<int> can also be used to represent weighted edge

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(edge(u, v, w));
		edges.push_back(edge(v, u, w)); // comment out for directed graph
	}

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF)); // n+1 since nodes are numbered 1 to n

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (auto e : edges) {
		int i = e.u; int j = e.v; int w = e.w;
		// dp[i][j] = w;
		dp[i][j] = min(dp[i][j], w); // use this if graph has parallel edges
	}

	// time : O(n^3)

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}