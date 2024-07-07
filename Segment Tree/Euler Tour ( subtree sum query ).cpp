#include <bits/stdc++.h>
using namespace std;

vector<int> value;
vector<int> seg;
vector<vector<int>> adj;
const int N = 2e5 + 1;
int in[N], out[N], flat_tree[N];
int timer = 0;
int n;

void dfs(int u, int par) {
    in[u] = ++timer;
    flat_tree[in[u]] = value[u];
    for (auto x : adj[u]) {
        if (x != par) {
            dfs(x, u);
        }
    }
    out[u] = timer;  
}

void build(int index, int lo, int hi) {
    if (lo == hi) {
        seg[index] = flat_tree[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2 * index, lo, mid);
    build(2 * index + 1, mid + 1, hi);
    seg[index] = max(seg[2 * index], seg[2 * index + 1]);
}

void update(int index, int lo, int hi, int node, int val) {
    if (lo == hi) {
        seg[index] = val;
        return;
    }
    int mid = (lo + hi) / 2;
    if (node <= mid) update(2 * index, lo, mid, node, val);
    else update(2 * index + 1, mid + 1, hi, node, val);
    seg[index] = max(seg[2 * index], seg[2 * index + 1]);
}

int query(int index, int lo, int hi, int l, int r) {
    if (hi < l || r < lo) return INT_MIN;
    if (l <= lo && hi <= r) return seg[index];
    int mid = (lo + hi) / 2;
    int left = query(2 * index, lo, mid, l, r);
    int right = query(2 * index + 1, mid + 1, hi, l, r);
    return max(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
    cin >> n;
    int q;
    cin >> q;
    value.clear();
    value.resize(n + 1);
    adj.clear();
    adj.resize(n + 1);
    seg.clear();
    seg.resize(4 * n + 1);
    for (int i = 1; i <= n; ++i) cin >> value[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    build(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int node, val;
            cin >> node >> val;
            update(1, 1, n, in[node], val);
            value[node] = val;
        } else {
            int sub;
            cin >> sub;
            int l = in[sub];
            int r = out[sub];
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
