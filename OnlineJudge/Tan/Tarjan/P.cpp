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
// Created: 2026-04-21 21:31

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "P"

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

void testcase() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vector<int> tin(n + 1, 0), low(n + 1, 0), sz(n + 1, 0);
    vector<bool> vis(n + 1, false);
    int timer = 0;
    int total_bridges = 0;
    ll bridge_ways = 0;
    
    auto dfs = [&](auto& self, int u, int p) -> void {
        vis[u] = true;
        tin[u] = low[u] = ++timer;
        sz[u] = 1;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                self(self, v, u);
                sz[u] += sz[v];
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    total_bridges++;
                    bridge_ways += 1LL * sz[v] * (n - sz[v]) - 1;
                }
            }
        }
    };
    
    vector<int> comps;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(dfs, i, 0);
            comps.pb(sz[i]);
        }
    }
    
    if (comps.size() > 2) {
        cout << 0 << el;
    } else if (comps.size() == 2) {
        ll ways = 1LL * comps[0] * comps[1] * (m - total_bridges);
        cout << ways << el;
    } else {
        ll non_bridges = m - total_bridges;
        ll all_new_edges = 1LL * n * (n - 1) / 2 - m;
        ll ways = bridge_ways + non_bridges * all_new_edges;
        cout << ways << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; 
    while (t--) testcase();

    return 0;
}