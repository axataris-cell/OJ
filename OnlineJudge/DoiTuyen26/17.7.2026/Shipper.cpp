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
// Created: 2026-07-17 09:33

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Shipper"

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

const int MAXN = 1e5 + 5;

vector<pll> g[MAXN];

vector<int> low(MAXN, 0), tin(MAXN, 0);
vector<int> val(MAXN, 0);

const int LOG = 20;
vector<int> dista(MAXN, 0);
vector<vector<int>> par(LOG, vector<int>(MAXN, 1));
vector<vector<int>> dist(67, vector<int>(MAXN, LINF));
vector<int> ID(MAXN, -1);
vector<int> special;
vector<int> h(MAXN, 0);

int timeDfs = 0;

void dfs(int u, int p) {
    tin[u] = low[u] = ++timeDfs;
    for (auto &[v, w] : g[u]) {
        if (v == p) continue;
        if (!tin[v]) {
            h[v] = h[u] + 1;
            par[0][v] = u;
            dista[v] = dista[u] + w;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], tin[v]);
            special.push_back(u);
            special.push_back(v);
        }
    }
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

int length(int u, int v) {
    int k = lca(u, v);
    return dista[u] + dista[v] - 2 * dista[k];
}

void dijkstra(int u, int id) {
    pqueue<pll, vector<pll>, greater<pll>> pq;

    dist[id][u] = 0;
    pq.emplace(dist[id][u], u);

    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[id][u]) continue;
        for (auto &[v, w] : g[u]) {
            if (dist[id][v] > dist[id][u] + w) {
                dist[id][v] = dist[id][u] + w;
                pq.emplace(dist[id][v], v);
            }
        }
    }
}

void testcase() {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].pb({b, w});
        g[b].pb({a, w}); 
    }
    prep(n);
    sort(all(special));
    special.erase(unique(all(special)), special.end());
    for (int i = 0; i < special.size(); i++) {
        ID[special[i]] = i;
        dijkstra(special[i], i);
    }

    while (q--) {
        int a, b; cin >> a >> b;
        int res = LINF;
        for (auto u : special) {
            int id = ID[u];
            int d = length(a, u) + dist[id][b];
            res = min(res, d);
        }
        res = min(res, length(a, b));
        cout << res << el;
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