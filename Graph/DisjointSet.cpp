class DisjointSet {
  vi rank, parent, size;
 public:
  // n is no. of nodes
  DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    size.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }
  int findup(int node) {
    if (node == parent[node]) return node;
    return parent[node] = findup(parent[node]);
  }
  void unionByRank(int u, int v) {
    int pu = findup(u);
    int pv = findup(v);
    if (pu == pv) return;
    if (rank[pu] < rank[pv]) {
      parent[pu] = pv;
    } else if (rank[pu] < rank[pv]) {
      parent[pv] = pu;
    } else {
      parent[pv] = pu;
      rank[pu]++;
    }
  }
  void unionBySize(int u, int v) {
    int pu = findup(u);
    int pv = findup(v);
    if (pu == pv) return;
    if (size[pu] < size[pv]) {
      parent[pu] = pv;
      size[pv] += size[pu];
    } else {
      parent[pv] = pu;
      size[pu] += size[pv];
    }
  }
};
int32_t main() {
  // sieve();
  // SPF();
  sped int t;
  t = 1;
  while (t--) {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 belong to same component or not
    if (ds.findup(3) == ds.findup(7)) {
      cout << "Same\n";
    } else
      cout << "Not same\n";
    ds.unionBySize(3, 7);
    if (ds.findup(3) == ds.findup(7)) {
      cout << "Same\n";
    } else
      cout << "Not same\n";
  }
}
