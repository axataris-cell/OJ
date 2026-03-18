#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 10:26

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 1e5 + 5;
const int LOG = 30;

int n, q;

vector<pii> g[MAXN];
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
vector<int> dist(MAXN, 0), h(MAXN, 0);

void dfs(int u, int p) {
    for (pii x : g[u]) {
        int v = x.first, w = x.second;
        if (v == p) continue;
        par[0][v] = u;
        h[v] = h[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

void preprocess() {
    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for (int i = 0; i <= LOG; i++) {
            if ((k >> i) & 1) {
                u = par[i][u];
            }
        }
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }

    return par[0][u];
}

int kth_anc(int u, int k) {
    int v = u;
    for (int i = LOG; i >= 0; i--) {
        if ((k >> i) & 1) v = par[i][v];
    }
    return v;
}

int query(int u, int v, int k) {
    int anc = lca(u, v);
    int d = h[u] - h[anc] + 1;
    if (k <= d) return kth_anc(u, k - 1);
    int d2 = h[v] - h[anc];
    int d1 = k - d;
    return kth_anc(v, d2 - d1);
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    dfs(1, 1);
    preprocess();

    // for (int i = 0; i <= LOG; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << par[i][j] << ' ';
    //     }
    //     cout << el;
    // }
    // cout << kth_anc(4, 1) << ' ' << kth_anc(4, 2);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int u, v; cin >> u >> v;
            cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << el;
        } else {
            int u, v, k; cin >> u >> v >> k;
            cout << query(u, v, k) << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}