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
// Created: 2026-07-18 15:34

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "EMST"

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


#define int long long

const int MAXN = 2e5 + 5;

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

    void make(int u) {
        sz[u] = 1;
        par[u] = u;
    }

    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
};

struct Edge {
    int u, v, w;
    int id;
    bool mst;
};

vector<pii> g[MAXN];
const int LOG = 25;
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
vector<vector<int>> mx(LOG + 1, vector<int>(MAXN, 0));
bool vis[MAXN];
vector<int> h(MAXN, 0);

void dfs(int u, int p) {
    vis[u] = true;  
    for (auto &[v, w] : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[0][v] = u;
        mx[0][v] = w;
        dfs(v, u);
    }
}

void prep (int &n) {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, i);
    }
    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][par[i - 1][j]]);
        }
    }
}

int lcamx(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int res = 0;
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for (int i = 0; i <= LOG; i++) {
            if (k >> i & 1) {
                res = max(res, mx[i][u]);
                u = par[i][u];
            }
        }
    }

    if (u == v) return res;

    for (int i = LOG; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            res = max({res, mx[i][u], mx[i][v]});
            u = par[i][u];
            v = par[i][v];
        }
    }
    
    return max({res, mx[0][u], mx[0][v]});
}

void testcase() {
    int n, m; cin >> n >> m;
    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.pb({a, b, w, i, false});
    }

    sort(all(edges), [](const Edge &x, const Edge &y) {
        return x.w < y.w;
    });
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.make(i);
    ll cur = 0;
    for (auto &[u, v, w, id, mst] : edges) {
        if (dsu.unite(u, v)) {
            g[u].pb({v, w});
            g[v].pb({u, w});
            cur += w;
            mst = true;
        }
    }
    prep(n);
    vector<int> ans(m + 1, 0);
    for (auto &[u, v, w, id, mst] : edges) {
        if (mst) {
            ans[id] = cur;
            continue;
        }
        int k = lcamx(u, v);
        ans[id] = cur - k + w;
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << el;
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