#include <bits/stdc++.h>
using namespace std;

void addEdge(unordered_map<int, list<int>> &adj, int u, int v,
             bool isdirected) {
  // if is directed graph then isdirected == true
  // if is undirected graph then isdirected == false

  // create an edje from u to v
  adj[u].push_back(v);
  if (isdirected == false) {
    adj[v].push_back(u);
  }
}
void printAdjList(unordered_map<int, list<int>> &adj) {
  for (auto i : adj) {
    cout << i.first << "->";
    for (auto j : i.second) {
      cout << j << ",";
    }
    cout << '\n';
  }
}

void bfs(unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited,
         vector<int> &ans, int node) {
  queue<int> q;
  q.push(node);
  visited[node] = 1;

  while (!q.empty()) {
    int frontNode = q.front();
    q.pop();

    ans.push_back(frontNode);

    for (auto i : adj[frontNode]) {
      if (!visited[i]) {
        q.push(i);
        visited[i] = 1;
      }
    }
  }
}

vector<int> bfsTraversal(int n, unordered_map<int, list<int>> &adj) {
  unordered_map<int, bool> visited;
  vector<int> ans;

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      bfs(adj, visited, ans, i);
    }
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the number of nodes" << '\n';
  cin >> n;
  cout << "Enter the number of edges" << '\n';
  int m;
  cin >> m;
  cout << "Enter 0 to make undirected graph or 1 to make directed graph"
       << '\n';
  bool f;
  cin >> f;
  unordered_map<int, list<int>> adj;
  cout << "Enter u and v " << '\n';
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    addEdge(adj, u, v, f);
  }
  cout << "Adjacency List: " << '\n';
  printAdjList(adj);
  vector<int> bfs = bfsTraversal(n, adj);
  cout << "BFS Traversal: ";
  for (auto x : bfs) {
    cout << x << " ";
  }
  cout << '\n';
}
