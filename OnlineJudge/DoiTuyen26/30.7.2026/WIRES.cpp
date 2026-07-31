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
// Created: 2026-07-30 14:57

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "wires"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

#define int long long

struct Edge {
    int u, v, w;
};
vector<Edge> edges;

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

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
}; 

void testcase() {
    int n; cin >> n;
    vector<pii> coords(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> coords[i].fi >> coords[i].se;
    }
    for (int i = 1; i < n; i++) {
        auto &[x, y] = coords[i];
        for (int j = i + 1; j <= n; j++) {
            if (i == j) continue;
            auto &[a, b] = coords[j];
            int dx = abs(x - a);
            int dy = abs(y - b);
            edges.pb({i, j, dx + dy - __gcd(dx, dy)});
        }
    }
    sort(all(edges), [](const Edge &x, const Edge &y) {
        return x.w < y.w;
    });

    // for (auto &[u, v, w] : edges) {
    //     cout << u << ' ' << v << ' ' << w << el;
    // }
    // return;

    DSU dsu(n);
    for (int i = 1; i <= n; i++) dsu.make(i);

    vector<pii> res;
    int cnt = 0;
    for (auto &[u, v, w] : edges) {
        if (res.size() == n - 1) break;
        if (dsu.unite(u, v)) {
            cnt += w;
            res.pb({u, v});
        };
    }

    cout << cnt << el;
    for (auto &[u, v] : res) {
        cout << u << ' ' << v << el;
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