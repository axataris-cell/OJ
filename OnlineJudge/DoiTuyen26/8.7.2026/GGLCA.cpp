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
// Created: 2026-07-08 09:04

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "GGLCA"

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

int n; 

vector<int> g[MAXN];
vector<int> h(MAXN, 0);
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
vector<int> tin(MAXN, 0), tout(MAXN, 0);

int timeDfs = 0;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[0][v] = u;
        dfs(v, u);
    }
    tout[u] = timeDfs;
}

void prep() {
    dfs(1, 1);
    for (int l = 1; l <= LOG; l++) {
        for (int i = 1; i <= n; i++) {
            par[l][i] = par[l - 1][par[l - 1][i]];
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for (int i = 0; i <= LOG; i++) {
            if (k >> i & 1) {
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

void testcase() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    prep();
    int q; cin >> q;
    while (q--) {
        int r, u, v; cin >> r >> u >> v;
        int a = lca(u, v);
        int b = lca(u, r);
        int c = lca(v, r);

        if (a == b)
            cout << c << el;
        else if (a == c)
            cout << b << el;
        else
            cout << a << el;
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