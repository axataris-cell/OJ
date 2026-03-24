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
// Created: 2026-03-24 19:32

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "144"

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

// code giải vip pro

const int MAXN = 105;

int n, m;
pii s, t;

int g[MAXN][MAXN];

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n) {}

    void make(int u) {
        sz[u] = 1;
        par[u] = u;
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
};

struct Edge {
    int u, v;
    int w;
};

vector<Edge> edges;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int id(int x, int y) { // id ô
    return x * m + y;
}

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void prepare_edges() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (valid(nx, ny)) {
                    edges.pb({id(i, j), id(nx, ny), abs(g[i][j] - g[nx][ny])});
                }
            }
        }
    }
    sort(all(edges), [](Edge x, Edge y) {
        return x.w < y.w;
    });
}

void testcase() {
    cin >> n >> m;
    cin >> s.fi >> s.se >> t.fi >> t.se;
    --s.fi; --s.se; --t.fi; --t.se;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    prepare_edges();
    DSU dsu(n * m);
    for (int i = 0; i < n * m; i++) dsu.make(i);
    int res = 0;
    for (auto e : edges) {
        if (dsu.find(id(s.fi, s.se)) == dsu.find(id(t.fi, t.se))) break;
        if (dsu.unite(e.u, e.v)) {
            res = max(res, e.w);
        }
        // cerr << e.u << ' ' << e.v << ' ' << e.w << el;
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