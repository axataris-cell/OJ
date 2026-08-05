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
// Created: 2026-08-03 14:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "PHUCHOI"

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

struct Edge {
    int u, v, w;
};

vector<Edge> edges;

struct DSU {
    vector<int> sz, par, activated;

    DSU(int n) : sz(n + 1), par(n + 1), activated(n + 1) {}

    void init(int u) {
        sz[u] = 1;
        par[u] = u;
        activated[u] = 0;
    }

    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        activated[u] |= activated[v];
    }
};

struct Query {
    int x, id;
};

void testcase() {
    int n, m, k, q; cin >> n >> m >> k >> q;

    DSU dsu(n);
    for (int i = 1; i <= n; i++) dsu.init(i);

    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        dsu.activated[dsu.find(x)] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges.pb({a, b, c});
    }

    vector<Query> queries;
    vector<int> ans(q + 1, 0);

    for (int i = 1; i <= q; i++) {
        int x; cin >> x;
        queries.pb({x, i});
    }

    sort(all(queries), [](const Query &x, const Query &y) {
        return x.x > y.x;
    });
    sort(all(edges), [](const Edge &x, const Edge &y) {
        return x.w > y.w;
    });

    int curans = k; // ti tru k di la ok
    int p = 0; // point q

    for (auto &[x, id] : queries) {
        while (p < m && edges[p].w >= x) {
            int u = edges[p].u;
            int v = edges[p].v;
            u = dsu.find(u);
            v = dsu.find(v);
            if (dsu.activated[u]) curans -= dsu.sz[u];
            if (dsu.activated[v] && u != v) curans -= dsu.sz[v];
            dsu.unite(u, v);
            u = dsu.find(u);
            if (dsu.activated[u]) curans += dsu.sz[u];
            ++p;
        }
        ans[id] = curans - k;
    }

    // for (auto &[u, v, w] : edges) {
    //     while (p < q && queries[p].x <= w) {
    //         ans[queries[p].id] = curans - k;
    //         ++p;
    //     }
    //     u = dsu.find(u);
    //     v = dsu.find(v);
    //     if (dsu.activated[u]) curans -= dsu.sz[u];
    //     if (dsu.activated[v]) curans -= dsu.sz[v];
    //     dsu.unite(u, v);
    //     u = dsu.find(u);
    //     if (dsu.activated[u]) curans += dsu.sz[u];
    // }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << el;
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