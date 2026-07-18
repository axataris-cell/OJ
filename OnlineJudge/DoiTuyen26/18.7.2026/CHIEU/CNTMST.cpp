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
// Created: 2026-07-18 15:43

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "CNTMST"

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

const int MOD = 998244353;
const int MAXN = 2e5 + 5;

struct Edge {
    int u, v, w;
    int id;
};

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

    void make(int u) {
        sz[u] = 1;
        par[u] = u;
    }

    int find(int u) {
        if (u == par[u]) return u;
        return par[u] = find(par[u]);
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
    int n, m; 
    cin >> n >> m;
    
    vector<Edge> edges;
    for (int i = 1; i <= m; i++) {
        int a, b, w; cin >> a >> b >> w;
        edges.pb({a, b, w, -1});
    }

    sort(all(edges), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.make(i);

    ll res = 1;
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) j++;

        vector<pair<int, int>> cur_edges;
        for (int k = i; k < j; k++) {
            int u = dsu.find(edges[k].u);
            int v = dsu.find(edges[k].v);
            if (u != v) {
                cur_edges.pb({u, v});
            }
        }

        int k = cur_edges.size();
        if (k > 0) {
            vector<int> comps;
            for (auto& e : cur_edges) {
                comps.pb(e.fi);
                comps.pb(e.se);
            }
            sort(all(comps));
            comps.erase(unique(all(comps)), comps.end());

            auto get_id = [&](int u) {
                return lower_bound(all(comps), u) - comps.begin();
            };

            int max_add = 0;
            DSU local_dsu(comps.size());
            for (int x = 0; x < comps.size(); x++) local_dsu.make(x);

            for (auto& e : cur_edges) {
                if (local_dsu.unite(get_id(e.fi), get_id(e.se))) {
                    max_add++;
                }
            }

            ll ways = 0;
            for (int mask = 0; mask < (1 << k); mask++) {
                if (__builtin_popcount(mask) == max_add) {
                    DSU temp_dsu(comps.size());
                    for (int x = 0; x < comps.size(); x++) temp_dsu.make(x);
                    
                    bool ok = true;
                    for (int bit = 0; bit < k; bit++) {
                        if ((mask >> bit) & 1) {
                            if (!temp_dsu.unite(get_id(cur_edges[bit].fi), get_id(cur_edges[bit].se))) {
                                ok = false;
                                break;
                            }
                        }
                    }
                    if (ok) ways++;
                }
            }

            res = (res * ways) % MOD;

            for (auto& e : cur_edges) {
                dsu.unite(e.fi, e.se);
            }
        }
        
        i = j;
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; 
    while (t--) testcase();

    return 0;
}