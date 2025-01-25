/*

Implementation of graph search using

  1. depth first search   (dfs)

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

using namespace std;

// time : O(V + 2E)
// space: V due to fn call stack + V due to vis[] ~ O(V)

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& vis) {

  vis[u] = true;

  cout << u << " ";

  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, adj, vis);
    }
  }

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

  int s = 0; // src node

  vector<bool> vis(n, false); // vis[i] stores if the ith node is visited or not

  dfs(s, adj, vis);

  return 0;

}