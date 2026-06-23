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
// Created: 2026-06-23 08:23

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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

const int MAXN = 3e5 + 5;
const int LOG = 20;

struct Edge {
    int u, v;
} edges[MAXN];

vector<pii> g[MAXN];
int up[MAXN][LOG];
int depth[MAXN], parent_node[MAXN], up_edge[MAXN];
int dsu[MAXN], s_min[MAXN], ans[MAXN];
bool is_tree[MAXN];
vector<int> unblocks[MAXN];

void dfs(int u, int p, int edge_id, int d) {
    parent_node[u] = p;
    up_edge[u] = edge_id;
    depth[u] = d;
    up[u][0] = p;
    for (int j = 1; j < LOG; ++j) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for (auto &[v, id] : g[u]) {
        if (v != p) {
            dfs(v, u, id, d + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = LOG - 1; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = up[u][j];
        }
    }
    if (u == v) return u;
    for (int j = LOG - 1; j >= 0; --j) {    
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int get_dsu(int u) {
    return dsu[u] == u ? u : dsu[u] = get_dsu(dsu[u]);
}

void testcase() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; ++i) g[i].clear();
    for (int i = 1; i <= m; ++i) {
        unblocks[i].clear();
        is_tree[i] = false;
        s_min[i] = INF;
    }

    for (int i = 1; i <= m; ++i) {
        cin >> edges[i].u >> edges[i].v;
    }

    for (int i = 0; i < n - 1; ++i) {
        int id; cin >> id;
        is_tree[id] = true;
    }

    for (int i = 1; i <= m; ++i) {
        if (is_tree[i]) {
            g[edges[i].u].pb({edges[i].v, i});
            g[edges[i].v].pb({edges[i].u, i});
        }
    }

    dfs(1, 0, 0, 0);

    for (int i = 1; i <= n; ++i) dsu[i] = i;

    for (int i = 1; i <= m; ++i) {
        if (is_tree[i]) continue;
        int u = edges[i].u, v = edges[i].v;
        int l = lca(u, v);

        int curr = get_dsu(u);
        while (depth[curr] > depth[l]) {
            s_min[up_edge[curr]] = i;
            dsu[curr] = get_dsu(parent_node[curr]);
            curr = dsu[curr];
        }

        curr = get_dsu(v);
        while (depth[curr] > depth[l]) {
            s_min[up_edge[curr]] = i;
            dsu[curr] = get_dsu(parent_node[curr]);
            curr = dsu[curr];
        }
    }

    pqueue<int> pq;
    
    for (int i = 1; i <= m; ++i) {
        if (!is_tree[i]) {
            pq.push(i);
        } else {
            if (s_min[i] == INF) {
                pq.push(i);
            } else {
                unblocks[s_min[i]].pb(i);
            }
        }
    }

    for (int val = m; val >= 1; --val) {
        int curr = pq.top();
        pq.pop();
        ans[curr] = val;

        if (!is_tree[curr]) {
            for (int nxt : unblocks[curr]) {
                pq.push(nxt);
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << (i == m ? "" : " ");
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; // cin >> t;
    while (t--) testcase();

    return 0;
}