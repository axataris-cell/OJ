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
// Created: 2026-08-09 20:21

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "E"

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
const int LOG = 20;
const int BLOCK = 320;

struct Query {
    int type, u, id;  
};
vector<Query> queries[BLOCK];

vector<int> g[MAXN];
int ans[MAXN];
int h[MAXN];
vector<vector<int>> par(LOG, vector<int>(MAXN, 1));
int dist[MAXN];
bool isqury[MAXN];

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[0][v] = u;
        dfs(v, u);
    }
}

void prep(int n) {
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) par[i][j] = par[i - 1][par[i - 1][j]];
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

int relative_dist(int u, int v) {
    return h[u] + h[v] - 2 * h[lca(u, v)];
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1, 1);
    prep(n);
    for (int i = 1; i <= n; i++) dist[i] = h[i];
    for (int i = 1; i <= q; i++) {
        int t, u; cin >> t >> u;
        int curB = (i - 1) / BLOCK;
        queries[curB].pb({t, u, i});
        if (t == 2) isqury[i] = true;
    }

    int MAX_BLOCK_SIZE = (q - 1) / BLOCK;
    vector<int> last;
    last.reserve(BLOCK + 1);
    vector<int> vis(n + 1, 0);
    int visCount = 0;
    
    for (int i = 0; i <= MAX_BLOCK_SIZE; i++) {
        // vinamilk
        queue<int> q;
        while (last.size()) {
            int u = last.back(); last.pop_back();
            q.push(u);
        }
        ++visCount;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (vis[v] != visCount) {
                    vis[v] = visCount;
                    dist[v] = min(dist[v], dist[u] + 1);
                    q.push(v);
                }
            }
        }
        // qury
        for (auto &[t, u, id] : queries[i]) {
            if (t == 1) {
                dist[u] = 0;
                last.pb(u);
            } else {
                int bestdist = dist[u];
                for (auto v : last) {
                    bestdist = min(bestdist, relative_dist(u, v));    
                }
                ans[id] = (bestdist == INF ? -1 : bestdist);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        if (isqury[i]) {
            cout << ans[i] << el;
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