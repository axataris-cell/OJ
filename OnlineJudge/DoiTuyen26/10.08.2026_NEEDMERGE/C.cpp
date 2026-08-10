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
// Created: 2026-08-10 16:00

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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

vector<int> g[MAXN];

const int LOG = 20;

vector<vector<int>> par(LOG, vector<int>(MAXN, 1));
int h[MAXN];

void dfs_lca(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        par[0][v] = u;
        h[v] = h[u] + 1;
        dfs_lca(v, u);
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for (int i = 0; i < LOG; i++) {
            if (k >> i & 1) u = par[i][u];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    
    return par[0][u];
}

int distance(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

int child[MAXN];
bool del[MAXN];

void countChild(int u, int p) {
    child[u] = 1;
    for (int v : g[u]) if (v != p && !del[v]) {
        countChild(v, u);
        child[u] += child[v];
    }
}

int findCentroid(int u, int p, int n) {
    for (int v : g[u]) {
        if (!del[v] && v != p && child[v] > n / 2) return findCentroid(v, u, n);
    }
    return u;
}

int parCentroid[MAXN]; // parCentroid in centroid tree
int dist[MAXN];

void buildCentroid(int n) {
    countChild(1, 1);
    int r = findCentroid(1, 1, n);
    queue<int> q;
    q.push(r);
    parCentroid[r] = r;
    del[r] = true;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (del[v]) continue;
            countChild(v, v);
            int nu = findCentroid(v, v, child[v]);
            del[nu] = true;
            parCentroid[nu] = u;
            q.push(nu);
        }
    }
}

void update(int u) {
    int bruh = u;
    dist[u] = 0;
    while (parCentroid[u] != u) {
        u = parCentroid[u];
        dist[u] = min(dist[u], distance(bruh, u));
    }
}

int query(int u) {
    int bestdist = dist[u];
    int bruh = u;
    while (u != parCentroid[u]) {
        u = parCentroid[u];
        bestdist = min(bestdist, dist[u] + distance(bruh, u));
    }
    return bestdist;
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs_lca(1, 1);
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) par[i][j] = par[i - 1][par[i - 1][j]];
    }
    buildCentroid(n);
    for (int i = 1; i <= n; i++) dist[i] = INF;
    update(1);
    while (q--) {
        int t, u; cin >> t >> u;
        if (t == 1) {
            update(u);
        } else {
            cout << query(u) << el;
        }
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