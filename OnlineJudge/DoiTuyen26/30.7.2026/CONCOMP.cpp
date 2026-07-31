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
// Created: 2026-07-30 15:24

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "CONCOMP"

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

const int MAXM = 3e4 + 5;
const int BLOCK = 250;

struct History {
    int u, oldsz, oldCmpCnt;
};
stack<History> history;

int compCnt;
struct DSU {
    vector<int> sz, par;
    
    DSU(int n) : sz(n + 1), par(n + 1) {}

    void make(int u) {
        sz[u] = 1;
        par[u] = u;
    }

    int find(int u) {
        if (u == par[u]) return u;
        return find(par[u]);
    } // no path comp

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        history.push({v, sz[v], compCnt});
        history.push({u, sz[u], compCnt});
        sz[u] += sz[v];
        par[v] = u;
        --compCnt;
        return;
    }
};

struct Edge {
    int x, y;
};

struct Query {
    int l, r, id;
};

void testcase() {
    int n, m; cin >> n >> m; compCnt = n;
    vector<Edge> edges(2 * m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].x >> edges[i].y;
        edges[i + m] = edges[i];
    }

    int MAXBLOCK = (2 * m + BLOCK - 1) / BLOCK;
    vector<vector<Query>> queries(MAXBLOCK);

    int q; cin >> q;
    vector<int> ans(q + 1, 0);
    for (int i = 1; i <= q; i++) {
        int L, R; cin >> L >> R;
        int l = R + 1;
        int r = L + m - 1;
        if (l > r) {
            ans[i] = n;
            continue;
        }
        int B = (l - 1) / BLOCK;
        queries[B].pb({l, r, i});
    }

    DSU dsu(n);
    for (int i = 1; i <= n; i++) dsu.make(i);
    
    for (int B = 0; B < MAXBLOCK; B++) {
        vector<Query> heavy;
        for (auto &[l, r, id] : queries[B]) {
            if (r - l + 1 <= BLOCK) {
                for (int i = l; i <= r; i++) {
                    dsu.unite(edges[i].x, edges[i].y);
                }
                ans[id] = compCnt;
                while (history.size()) {
                    auto [u, sz, cmpcnt] = history.top(); history.pop();
                    dsu.par[u] = u;
                    dsu.sz[u] = sz;
                    compCnt = cmpcnt;
                }
            } else heavy.pb({l, r, id});
        }

        sort(all(heavy), [](const Query &x, const Query &y) {
            return x.r < y.r;
        });
        
        int E = (B + 1) * BLOCK;
        int cur_R = E - 1;

        for (auto &[l, r, id] : heavy) {
            while (cur_R < r) {
                ++cur_R;
                dsu.unite(edges[cur_R].x, edges[cur_R].y);
            }
            // temp
            int cursz = history.size();
            for (int i = l; i < E; i++) {
                dsu.unite(edges[i].x, edges[i].y);
            }

            ans[id] = compCnt;

            while (history.size() > cursz) {
                auto [u, sz, cmpcnt] = history.top(); history.pop();
                dsu.par[u] = u;
                dsu.sz[u] = sz;
                compCnt = cmpcnt;
            }
        }

        while (history.size()) {
            auto [u, sz, cmpcnt] = history.top(); history.pop();
            dsu.par[u] = u;
            dsu.sz[u] = sz;
            compCnt = cmpcnt;
        }
    }
    
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