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
// Created: 2026-08-06 11:44

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "QTREEPATH"

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
const int LOGN = 20;

vector<int> g[MAXN];
int h[MAXN];
int par[MAXN][LOGN];
int diff[MAXN];
int val[MAXN];
int pref[MAXN];

void prep(int u, int p, int d) {
    h[u] = d;
    par[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v != p) {
            prep(v, u, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (h[u] - (1 << i) >= h[v]) {
            u = par[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int dist(int u, int v) {
    int lc = lca(u, v);
    return h[u] + h[v] - 2 * h[lc];
}

bool onpath(int x, int u, int v) {
    return dist(u, x) + dist(x, v) == dist(u, v);
}

void add_path(int u, int v, int val) {
    int lc = lca(u, v);
    diff[u] += val;
    diff[v] += val;
    diff[lc] -= 2 * val;
}

pii getinter(int a, int b, int c, int d) {
    int candidates[4] = {
        lca(a, c),
        lca(a, d),
        lca(b, c),
        lca(b, d)
    };

    vector<int> kept;
    for (int i = 0; i < 4; i++) {
        int x = candidates[i];
        if (onpath(x, a, b) && onpath(x, c, d)) {
            kept.pb(x);
        }
    }

    if (kept.empty()) return {-1, -1};

    int max_d = -1;
    int best_u = kept[0], best_v = kept[0];
    for (size_t i = 0; i < kept.size(); i++) {
        for (size_t j = i; j < kept.size(); j++) {
            int d_uv = dist(kept[i], kept[j]);
            if (d_uv > max_d) {
                max_d = d_uv;
                best_u = kept[i];
                best_v = kept[j];
            }
        }
    }

    if (max_d <= 0) return {-1, -1};
    return {best_u, best_v};
}

void dfs_diff(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            dfs_diff(v, u);
            diff[u] += diff[v];
        }
    }
    val[u] = diff[u];
}

void dfs_pref(int u, int p, int curp) {
    pref[u] = curp;
    for (int v : g[u]) {
        if (v != p) {
            dfs_pref(v, u, curp + val[v]);
        }
    }
}

void testcase() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    prep(1, 0, 1);

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        add_path(a, b, 1);

        auto inter = getinter(a, b, c, d);
        if (inter.first != -1) {
            add_path(inter.first, inter.second, -1);
        }
    }

    dfs_diff(1, 0);
    dfs_pref(1, 0, 0);

    while (q--) {
        int e, f;
        cin >> e >> f;
        int lca_ef = lca(e, f);
        int ans = pref[e] + pref[f] - 2 * pref[lca_ef];
        cout << ans << el;
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