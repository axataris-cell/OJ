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
// Created: 2026-07-13 09:27

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TruyVanCayCon"

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

struct Edge {
    int v, w, id;
};
vector<Edge> g[MAXN];

struct Fenwick {
    vector<ll> bit;
    int n;

    Fenwick(int sz) : n(sz), bit(sz + 1) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }

    ll query(int pos) {
        ll res = 0;
        for (; pos > 0; pos -= pos & (-pos)) {
            res += bit[pos];
        }
        return res;
    }
};

const int LOG = 30;

vector<int> tin(MAXN, 0), tout(MAXN, 0);
vector<int> a(MAXN, 0);
vector<vector<int>> par(LOG, vector<int>(MAXN, 1));
vector<int> mapedge(MAXN, 0);
vector<int> h(MAXN, 0);
int timeDfs = 1;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    for (auto &[v, w, id] : g[u]) {
        if (v == p) continue;
        par[0][v] = u;
        h[v] = h[u] + 1;
        a[v] = w;
        mapedge[id] = v;
        dfs(v, u);
    }
    tout[u] = ++timeDfs;
}

void prep(int &n) {
    dfs(1, 1);
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
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        int w; cin >> w;
        g[u].pb({v, w, i});
        g[v].pb({u, w, i});
    }
    prep(n);
    Fenwick BIT(timeDfs + 1);
    for (int i = 1; i <= n; i++) {
        BIT.update(tin[i], a[i]);
        BIT.update(tout[i], -a[i]);
    }
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            s = mapedge[s];
            int delta = x - a[s];
            BIT.update(tin[s], x - a[s]);
            BIT.update(tout[s], a[s] - x);
            a[s] = x;
        } else {
            int u, v; cin >> u >> v;
            int anc = lca(u, v);
            cout << BIT.query(tin[u]) + BIT.query(tin[v]) - 2 * BIT.query(tin[anc]) << el;
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