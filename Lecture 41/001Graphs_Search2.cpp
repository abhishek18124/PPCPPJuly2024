/*

Implementation of graph search using

  1. breadth first search   (bfs)

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

// time : O(V+2E)
// space: V-1 for queue when graph has star-like structure + V due vis[] ~ O(V)
// src is connected to all other nodes

void bfs(int s, const vector<vector<int>>& adj) {

  int n = adj.size();
  vector<bool> vis(n, false); // vis[i] stores if the ith node is visited or not
  queue<int> q; // to track nodes that are visited but not yet explored

  // visit the src node
  q.push(s);
  vis[s] = true;

  while (!q.empty()) {

    int u = q.front();
    q.pop();

    // explore node 'u'

    cout <<  u << " ";

    for (int v : adj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        q.push(v);
      }
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

  bfs(s, adj);

  return 0;

}