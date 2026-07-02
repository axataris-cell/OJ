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
// Created: 2026-07-01 09:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "bus"

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

const int MAXN = 1e6 + 5;

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

    void make(int i) {
        sz[i] = 1;
        par[i] = i;
    }

    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};

vector<pii> edges;
vector<pii> g[MAXN];
bool delEdge[MAXN]; // 0.. m
bool isBest[MAXN]; //0...m
vector<int> query;
vector<int> ans;

void testcase() {
    int n, m; cin >> n >> m;
    int q; cin >> q;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        edges.pb({a, b});
        g[a].pb({b, i});
        g[b].pb({a, i});
    }

    while (q--) {
        int x; cin >> x;
        delEdge[x - 1] = true;
        query.pb(x - 1);
    }

    // build SPG
    {
        vector<int> dist(n + 1, 0);
        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(1);
        dist[1] = 0;
        vis[1] = true;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &[v, i] : g[u]) {
                if (!vis[v] || dist[v] == dist[u] + 1) {
                    if (!vis[v]) q.emplace(v);

                    vis[v] = true;
                    dist[v] = dist[u] + 1;

                    isBest[i] = true;
                }
            }
        }
    }


    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.make(i);

    for (int i = 0; i < m; i++) {
        if (isBest[i] && !delEdge[i]) {
            dsu.join(edges[i].fi, edges[i].se);
        }
    }

    reverse(all(query));

    for (auto q : query) {
        ans.pb(dsu.sz[dsu.find(1)] - 1);
        if (isBest[q]) dsu.join(edges[q].fi, edges[q].se);
    }

    reverse(all(ans));

    for (auto x : ans) cout << x << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}

/*
6 7 5
1 2
1 3
3 2
2 4
2 5
3 5
5 6
5
2
4
1
3
*/