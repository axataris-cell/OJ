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
// Created: 2026-07-02 14:14

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "G"

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

int cur = 0;

struct DSU {
    vector<int> sz, par;
    vector<int> activated;

    DSU(int n) : sz(n), par(n), activated(n) {}

    void make(int u, int ac) {
        sz[u] = 1;
        par[u] = u;
        activated[u] = ac;
    }

    void activate(int u) {
        u = find(u);
        if (!activated[u]) cur += sz[u];
        activated[u] = 1;
    }

    int find(int u) {
        if (u == par[u]) return u;
        par[u] = find(par[u]);
        activated[u] |= activated[par[u]];
        return par[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);

        if (activated[u]) cur -= sz[u];
        if (activated[v]) cur -= sz[v];

        activated[u] |= activated[v];
        par[v] = u;
        sz[u] += sz[v];

        if (activated[u]) cur += sz[u];

        return;
    }
};

int n, m, Y;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int get_id(int x, int y) {
    return (x - 1) * m + y;
}

bool valid(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m;
}

void testcase() {
    cin >> n >> m >> Y;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    vector<vector<pii>> h(1e5 + 1);

    DSU dsu(n * m + 1);
    for (int i = 1; i <= n * m; i++) dsu.make(i, 0);
    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            h[a[i][j]].pb({i, j});
        }
    }
    for (int t = 1; t <= Y; t++) {
        for (auto [x, y] : h[t]) {
            if (x == 1 || x == n || y == 1 || y == m) dsu.activate(get_id(x, y));

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (valid(nx, ny) && a[nx][ny] <= t) {
                    dsu.unite(get_id(x, y), get_id(nx, ny));
                }
            }
        }

        cout << n * m - cur << el;
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