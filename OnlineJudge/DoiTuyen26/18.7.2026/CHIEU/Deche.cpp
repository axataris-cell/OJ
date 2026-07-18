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
// Created: 2026-07-18 15:10

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Deche"

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

struct Point {
    int x, y, z;
    int id;
};

inline int cost(const Point &x, const Point &y) {
    return min({abs(x.x - y.x), abs(x.y - y.y), abs(x.z - y.z)});
}

struct Edge {
    int u, v;
};

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

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
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z;
        points.pb({x, y, z, i});
    }

    vector<Point> p = points;
    
    vector<Edge> edges;
    
    sort(all(points), [](const Point &x, const Point &y) {
        return x.x < y.x;
    });
    for (int i = 1; i < points.size(); i++) {
        edges.push_back({points[i].id, points[i - 1].id});
    }

    sort(all(points), [](const Point &x, const Point &y) {
        return x.y < y.y;
    });
    for (int i = 1; i < points.size(); i++) {
        edges.push_back({points[i].id, points[i - 1].id});
    }

    sort(all(points), [](const Point &x, const Point &y) {
        return x.z < y.z;
    });
    for (int i = 1; i < points.size(); i++) {
        edges.push_back({points[i].id, points[i - 1].id});
    }

    sort(all(edges), [&](const Edge &x, const Edge &y) {
        const auto &[u, v] = x;
        const auto &[a, b] = y;
        return cost(p[u], p[v]) < cost(p[a], p[b]);
    });

    DSU dsu(n);
    for (int i = 0; i < n; i++) dsu.make(i);

    ll res = 0;

    for (auto &[u, v] : edges) {
        if (dsu.unite(u, v)) {
            res += cost(p[u], p[v]);
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