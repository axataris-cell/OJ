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
// Created: 2026-08-01 14:58

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TongDuongDi"

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

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n + 1), par(n + 1) {}

    void make(int u) {
        sz[u] = 1;
        par[u] = u;
    }

    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};

vector<int> g[MAXN];
int val[MAXN];

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    DSU dsu(n);
    for (int i = 1; i <= n; i++) dsu.make(i);

    vector<int> bruh(n + 1);
    for (int i = 1; i <= n; i++) {
        bruh[i] = i;
    }
    sort(bruh.begin() + 1, bruh.end(), [&](int x, int y) {return val[x] < val[y];});
    int res = 0;

    vector<bool> activated(n + 1, false);

    for (int i = 1; i <= n; i++) {
        int u = bruh[i];
        activated[u] = true;
        for (int v : g[u]) {
            if (!activated[v]) continue;
            int sz1 = dsu.sz[dsu.find(u)];
            int sz2 = dsu.sz[dsu.find(v)];
            res += val[u] * sz1 * sz2;
            dsu.unite(u, v);
        }
    }

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}