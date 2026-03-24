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
// Created: 2026-03-24 16:23

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "137"

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

const int MAXN = 1e5;

int s, t;
int n;

vector<int> g[MAXN];
vector<int> val(MAXN, 0);

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n) {}

    void make(int i) {
        sz[i] = 1;
        par[i] = i;
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
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
} dsu(MAXN);

struct Edge {
    int u, v;
    int w;
};

vector<int> par(MAXN, -1);
map<pii, bool> inEdge;
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (dsu.find(v) != dsu.find(u) || vis[v] || !inEdge[{u, v}]) continue;
        par[v] = u;
        dfs(v);
    }
}

void testcase() {
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i <= n; i++) dsu.make(i);

    int u, v;
    vector<Edge> edges;
    while (cin >> u >> v) {
        edges.pb({u, v, abs(val[u] - val[v])});
        g[u].pb(v);
        g[v].pb(u);
    }

    int res = 0;
    sort(all(edges), [](Edge x, Edge y) {return x.w < y.w;});

    for (auto e : edges) {
        if (dsu.find(s) == dsu.find(t)) break;
        if (dsu.unite(e.u, e.v)) {
            inEdge[{e.u, e.v}] = inEdge[{e.v, e.u}] = true;
        }
        res = max(res, e.w);
    }

    if (dsu.find(s) != dsu.find(t)) {
        cout << -1 << el;
        return;
    }

    dfs(s);

    vector<int> path;
    int cur = t;
    while (cur != -1) {
        path.pb(cur);
        cur = par[cur];
    }
    reverse(all(path));
    
    cout << res << el;
    for (auto x : path) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}