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
// Created: 2026-03-25 14:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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

const int MAXN = 2e5 + 5;
const int LOG = 30;

int n, m;

vector<int> g[MAXN];
vector<int> depth(MAXN, 0), sz(MAXN, 1), heavy(MAXN, -1), par(MAXN, 0);
vector<int> head(MAXN, 1), pos(MAXN, 0);
vector<int> ST(4 * MAXN, 0), lz(4 * MAXN, 0); // max ST
vector<int> order;

void dfs(int u, int p) {
    int best = 0;
    int bestnode = -1;
    for (int v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > best) {
            best = sz[v];
            bestnode = v;
        }
    }
    if (bestnode != -1) heavy[u] = bestnode;
}

int timeDfs = 0;
void decompose(int u, int h) {
    pos[u] = ++timeDfs;
    head[u] = h;

    if (heavy[u] != -1) decompose(heavy[u], h);

    for (int v : g[u]) {
        if (v == par[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

void push(int id, int l, int r) {
    if (lz[id] == 0) return;

    ST[id << 1] += lz[id];
    lz[id << 1] += lz[id];

    ST[id << 1 | 1] += lz[id];
    lz[id << 1 | 1] += lz[id];

    lz[id] = 0;
}

void updateST(int id, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id] += val;
        lz[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    updateST(id << 1, l, mid, ql, qr, val);
    updateST(id << 1 | 1, mid + 1, r, ql, qr, val);
    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int queryST(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return -INF;
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    
    return max(queryST(id << 1, l, mid, ql, qr), queryST(id << 1 | 1, mid + 1, r, ql, qr));
}

void update(int u, int v) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        updateST(1, 1, n, pos[head[u]], pos[u], 1);
        u = par[head[u]];
    }
    if (depth[u] < depth[v]) swap(u, v);
    updateST(1, 1, n, pos[u], pos[v], 1);
}

void testcase() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x; //event
        order.pb(x);
    }
    dfs(1, 1);
    decompose(1, 1);
    for (int u = 1; u <= n; u++) {
        for (int i = 1; i <= 4 * n; i++) {
            ST[i] = 0;
            lz[i] = 0;
        }
        for (auto v : order) {
            update(u, v);
        }
        int mx = queryST(1, 1, n, 1, n);
        cout << (mx > 2 ? 0 : 1) << el;
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