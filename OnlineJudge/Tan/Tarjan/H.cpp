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
// Created: 2026-04-16 08:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "DOANDUONGPHU"

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

const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;

struct Edge {
    int v, id;
};

vector<Edge> g[MAXN];
vector<pii> edges;
vector<int> low(MAXN, 0), num(MAXN, 0);
bool isBridge[MAXM];

int countBridge = 0;
int timeDfs = 0;

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

    void make(int u) {
        par[u] = u;
        sz[u] = 1;
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return;
    }
};

void dfs(int u, int p, int preEdge) {
    num[u] = low[u] = ++timeDfs;
    for (const auto &e : g[u]) {
        if (e.id == preEdge || e.v == p) continue;
        if (!num[e.v]) {
            dfs(e.v, u, e.id);
            low[u] = min(low[u], low[e.v]);
            if (low[e.v] == num[e.v]) {
                ++countBridge;
                isBridge[e.id] = true;
            }
        } else low[u] = min(low[u], num[e.v]);
    }
}

vector<int> adj[MAXN]; // block cut tree

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb({b, i});
        g[b].pb({a, i});
        edges.pb({ a, b});
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) {
            dfs(i, i, -1);
        }
    }

    // Block cut tree
    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.make(i);
    for (int i = 0; i < m; i++) {
        if (!isBridge[i]) {
            dsu.join(edges[i].fi, edges[i].se);
        }
    }

    map<pii, bool> addedEdge;
    for (int i = 0; i < m; i++) {
        if (isBridge[i] && !addedEdge[{edges[i].fi, edges[i].se}]) {
            int u = dsu.find(edges[i].fi);
            int v = dsu.find(edges[i].se);
            adj[u].pb(v);
            adj[v].pb(u);
            addedEdge[{edges[i].fi, edges[i].se}] = addedEdge[{edges[i].se, edges[i].fi}] = true;
        }
    }

    int leaf = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i && adj[i].size() == 1) {
            leaf++;
        }
    }

    cout << (leaf + 1) / 2 << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}