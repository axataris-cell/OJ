#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 5;

int n, q;
vector<int> adj[MAXN];
int color[MAXN];

// HLD arrays
int parent[MAXN], depth[MAXN], heavy[MAXN];
int head[MAXN], pos[MAXN], sz[MAXN];
int cur_pos;

// Segment Tree
vector<unordered_set<int>> seg;

// DFS 1: tính size và heavy child
int dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    int maxsz = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int sub = dfs(v, u);
        sz[u] += sub;
        if (sub > maxsz) {
            maxsz = sub;
            heavy[u] = v;
        }
    }
    return sz[u];
}

// DFS 2: gán head và pos
void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos;

    if (heavy[u])
        decompose(heavy[u], h);

    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

// Build segment tree
void build(int idx, int l, int r, vector<int>& base) {
    if (l == r) {
        seg[idx].insert(base[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid, base);
    build(idx<<1|1, mid+1, r, base);

    seg[idx] = seg[idx<<1];
    seg[idx].insert(seg[idx<<1|1].begin(), seg[idx<<1|1].end());
}

// Query segment tree
bool query_seg(int idx, int l, int r, int ql, int qr, int c) {
    if (qr < l || r < ql) return false;
    if (ql <= l && r <= qr) {
        return seg[idx].count(c);
    }
    int mid = (l + r) >> 1;
    return query_seg(idx<<1, l, mid, ql, qr, c) ||
           query_seg(idx<<1|1, mid+1, r, ql, qr, c);
}

// Query path u -> v
bool query_path(int u, int v, int c) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]])
            swap(u, v);
        if (query_seg(1, 1, n, pos[head[u]], pos[u], c))
            return true;
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    return query_seg(1, 1, n, pos[u], pos[v], c);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> color[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    decompose(1, 1);

    // build base array
    vector<int> base(n + 1);
    for (int i = 1; i <= n; i++)
        base[pos[i]] = color[i];

    seg.resize(4 * (n + 1));
    build(1, 1, n, base);

    while (q--) {
        int u, v, c;
        cin >> u >> v >> c;
        cout << (query_path(u, v, c) ? '1' : '0');
    }
    cout << '\n';
    return 0;
}
