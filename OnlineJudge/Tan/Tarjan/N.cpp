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
// Created: 2026-04-21 21:28

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "N"

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

const int MOD = 1e9 + 7;
const int MAXN = 200005;

struct Edge {
    int to;
    int id;
};

vector<Edge> adj[MAXN];
int U[MAXN], V[MAXN];
bool is_bridge[MAXN];

int tin[MAXN], low[MAXN], timer;
int comp[MAXN], comp_size[MAXN], num_comps;
int deg[MAXN];

void dfs_bridge(int u, int p_edge) {
    tin[u] = low[u] = ++timer;
    for (auto& edge : adj[u]) {
        int v = edge.to;
        int id = edge.id;
        
        if (id == p_edge) continue;
        
        if (tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs_bridge(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) {
                is_bridge[id] = true;
            }
        }
    }
}

void dfs_comp(int u, int id) {
    comp[u] = id;
    comp_size[id]++;
    for (auto& edge : adj[u]) {
        if (is_bridge[edge.id]) continue;
        int v = edge.to;
        if (!comp[v]) {
            dfs_comp(v, id);
        }
    }
}

void testcase() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        cin >> U[i] >> V[i];
        adj[U[i]].push_back({V[i], i});
        adj[V[i]].push_back({U[i], i});
    }

    dfs_bridge(1, 0);

    for (int i = 1; i <= n; i++) {
        if (!comp[i]) {
            num_comps++;
            dfs_comp(i, num_comps);
        }
    }

    if (num_comps == 1) {
        cout << 1 << ' ' << n << el;
        return;
    }

    for (int i = 1; i <= m; i++) {
        int u = U[i], v = V[i];
        if (comp[u] != comp[v]) {
            deg[comp[u]]++;
            deg[comp[v]]++;
        }
    }
    
    int min_size = 0;
    ll ways = 1;

    for (int i = 1; i <= num_comps; i++) {
        if (deg[i] == 1) {
            min_size++;
            ways = (ways * comp_size[i]) % MOD;
        }
    }
    
    cout << min_size << ' ' << ways << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}