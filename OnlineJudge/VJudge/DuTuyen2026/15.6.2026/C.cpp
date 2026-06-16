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
// Created: 2026-06-15 09:08

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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

const int MAXN = 200005;

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

    void make(int i) {
        sz[i] = 1;
        par[i] = i;
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};

DSU dsu1(MAXN), dsu2(MAXN);

vector<int> ga[MAXN];
vector<int> gb[MAXN];

void testcase() {
    int n, m, l; cin >> n >> m >> l;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        ga[u].pb(v);
        ga[v].pb(u);
    }

    for (int i = 1; i <= l; i++) {
        int u, v; cin >> u >> v;
        gb[u].pb(v);
        gb[v].pb(u);
    }

    for (int i = 1; i <= n; i++) {
        dsu1.make(i);
        dsu2.make(i);
    }

    {
        queue
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