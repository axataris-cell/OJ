#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define null nullptr
#define pb push_back
#define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-07-13 16:09

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ColorOnPath"

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

#ifdef LOCAL
   #define debug(x) cerr << x << '\n'
#else
   #define debug(x)
#endif

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1e5 + 5;


struct Node {
    int val;
    int l_id, r_id;
} pool[20 * MAXN];

struct PersistentSegmentTree {
    vector<int> roots;
    int nodeCnt;
    int n;
    
    PersistentSegmentTree(int sz) : n(sz), roots(sz + 1), nodeCnt(0) {}

    int create(int val = 0, int l_id = 0, int r_id = 0) {
        int cur_id = ++nodeCnt;
        pool[cur_id] = {val, l_id, r_id};
        return cur_id;  
    }
    
    int build(int l, int r) {
        int cur_id = create();
        if (l == r) {
            return cur_id;
        }
        int mid = (l + r) / 2;
        pool[cur_id].l_id = build(l, mid);
        pool[cur_id].r_id = build(mid + 1, r);
        pool[cur_id].val = pool[pool[cur_id].l_id].val + pool[pool[cur_id].r_id].val;
        return cur_id;
    }
    
    int update(int tree_id, int l, int r, int pos, int val) {
        int cur_id = create(pool[tree_id].val, pool[tree_id].l_id, pool[tree_id].r_id);
        if (l == r) {
            pool[cur_id].val += val;
            return cur_id;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) {
            pool[cur_id].l_id = update(pool[cur_id].l_id, l, mid, pos, val);
        } else {
            pool[cur_id].r_id = update(pool[cur_id].r_id, mid + 1, r, pos, val);
        }
        pool[cur_id].val = pool[pool[cur_id].l_id].val + pool[pool[cur_id].r_id].val;
        return cur_id;
    }
    
    int query(int tree_id, int l, int r, int ql, int qr) {
        if (!tree_id) return 0;
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) {
            return pool[tree_id].val;
        }
        int mid = (l + r) / 2;
        return query(pool[tree_id].l_id, l, mid, ql, qr) + query(pool[tree_id].r_id, mid + 1, r, ql, qr);
    }
};

const int LOG = 30;
vector<int> g[MAXN];
vector<int> h(MAXN, 0);
vector<int> col(MAXN, 0);
vector<vector<int>> par(LOG, vector<int>(MAXN, 1));

void dfs(int u, int p, PersistentSegmentTree &PST, int &n) {
    for (int v : g[u]) {
        if (v == p) continue;
        par[0][v] = u;
        h[v] = h[u] + 1;
        PST.roots[v] = PST.update(PST.roots[u], 1, n, col[v], 1);
        dfs(v, u, PST, n);
    }
}

void prep(int &n, PersistentSegmentTree &PST) {
    PST.roots[0] = PST.build(1, n);
    PST.roots[1] = PST.update(0, 1, n, col[1], 1);
    dfs(1, 1, PST, n);
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for (int i = 0; i < LOG; i++) {
            if (k >> i & 1) {
                u = par[i][u];
            }
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }

    return par[0][u];
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    PersistentSegmentTree PST(n);
    pool[0] = {0, 0, 0}; // nullptr ahhh

    prep(n, PST);

    while (q--) {
        int a, b, c; cin >> a >> b >> c;
        int lc = lca(a, b);
        int cnt = PST.query(PST.roots[a], 1, n, c, c) + PST.query(PST.roots[b], 1, n, c, c) - 2 * PST.query(PST.roots[lc], 1, n, c, c) + (col[lc] == c);
        cout << (cnt > 0 ? 1 : 0);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}