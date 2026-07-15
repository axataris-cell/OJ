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
// Created: 2026-07-15 09:07

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TruyVanDuongDi"

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

int n, q; 

vector<int> g[MAXN];
vector<int> h(MAXN, 0), heavy(MAXN, -1);
vector<int> pos(MAXN, 0), sz(MAXN, 1), head(MAXN, -1);
vector<int> par(MAXN, 1);

void dfs(int u, int p) {
    int mx = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            heavy[u] = v;
        }
    }
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

vector<int> ST(4 * MAXN, 0);

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id << 1, l, mid, pos, val);
    else update(id << 1 | 1, mid + 1, r, pos, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <=l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void update(int u, int val) {
    update(1, 1, n, pos[u], val);
}

int query(int a, int b) {
    int res = 0;
    while (head[a] != head[b]) {
        if (pos[head[a]] < pos[head[b]]) swap(a, b);
        res += query(1, 1, n, pos[head[a]], pos[a]);
        a = par[head[a]];
    }
    if (pos[a] > pos[b]) swap(a, b);
    res += query(1, 1, n, pos[a], pos[b]);
    return res;
}

void testcase() {
    cin >> n >> q;
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 1);
    decompose(1, 1);
    for (int u = 1; u <= n; u++) {
        update(u, val[u]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            update(s, x);
        } else {
            int s; cin >> s;
            cout << query(1, s) << el;
        }
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