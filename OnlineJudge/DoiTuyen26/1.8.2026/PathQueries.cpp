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
// Created: 2026-08-01 13:43

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "PathQueries"

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

const int MAXN = 1e5 + 5;
const int LOG = 25;

vector<int> g[MAXN];
int tin[MAXN], tout[MAXN];
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
int h[MAXN];

int timeDfs = 0;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == p) continue;
        par[0][v] = u;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
    tout[u] = timeDfs;
}

void prep(int n) {
    dfs(1, 1);
    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

bool isanc(int u, int v) {
    return tin[u] <= tin[v] && tin[v] <= tout[u];    
}

// int lca(int u, int v) {
//     if (isanc(u, v)) return u;
//     if (isanc(v, u)) return v;

//     for (int i = LOG; i >= 0; i--)
//         if (!isanc(par[i][u], v))
//             u = par[i][u];

//     return par[0][u];
// }

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    prep(n);
    for (int i = 1; i <= q; i++) {
        int t; cin >> t;
        vector<int> queries(t);
        for (int j = 0; j < t; j++) cin >> queries[j];
        for (auto &x : queries) x = par[0][x];
        int mxnode = 1;
        for (auto &x : queries) {
            if (h[x] > h[mxnode]) mxnode = x;
        }
        bool ok = true;
        for (auto &x : queries) {
            if (x == mxnode) continue;
            if (!isanc(x, mxnode)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? 1 : 0) << el;
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