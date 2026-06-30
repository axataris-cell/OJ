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
#define int long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-06-23 14:49

constexpr int INF = 2e9;
constexpr int LINF = 4e18;

#define FILENAME "H"

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

constexpr int MAXN = 100005;
constexpr int MAX_NODES = 4000005;

struct Node {
    int l, r;
    int cnt;
    int sum;
} tree[MAX_NODES];

int root[MAXN], up[MAXN][20], depth[MAXN];
vector<pll> adj[MAXN];
vector<int> edge_stations[MAXN];
vector<int> vals;
int node_cnt = 0, S = 0;

int update(int prev, int l, int r, int pos, int val) {
    int cur = ++node_cnt;
    tree[cur] = tree[prev];
    tree[cur].cnt++;
    tree[cur].sum += val;
    if (l == r) return cur;
    int mid = l + (r - l) / 2;
    if (pos <= mid) tree[cur].l = update(tree[prev].l, l, mid, pos, val);
    else tree[cur].r = update(tree[prev].r, mid + 1, r, pos, val);
    return cur;
}

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < 20; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto& edge : adj[u]) {
        int v = edge.fi;
        int id = edge.se;
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        root[v] = root[u];
        for (int c : edge_stations[id]) {
            int pos = lower_bound(all(vals), c) - vals.begin() + 1;
            root[v] = update(root[v], 1, S, pos, c);
        }
        dfs(v, u);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int walk(int n_u, int n_v, int n_lca, int l, int r, int Y) {
    int total_cnt = tree[n_u].cnt + tree[n_v].cnt - 2 * tree[n_lca].cnt;
    if (total_cnt == 0) return 0;
    if (l == r) {
        int cost = vals[l - 1];
        if (cost == 0) return total_cnt;
        return min(total_cnt, Y / cost);
    }
    int mid = l + (r - l) / 2;
    int left_sum = tree[tree[n_u].l].sum + tree[tree[n_v].l].sum - 2 * tree[tree[n_lca].l].sum;
    int left_cnt = tree[tree[n_u].l].cnt + tree[tree[n_v].l].cnt - 2 * tree[tree[n_lca].l].cnt;
    if (Y >= left_sum) {
        return left_cnt + walk(tree[n_u].r, tree[n_v].r, tree[n_lca].r, mid + 1, r, Y - left_sum);
    } else {
        return walk(tree[n_u].l, tree[n_v].l, tree[n_lca].l, l, mid, Y);
    }
}

void testcase() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        edge_stations[i].clear();
    }
    vals.clear();
    node_cnt = 0;

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
    }

    for (int i = 1; i <= m; ++i) {
        int p;
        int c;
        cin >> p >> c;
        edge_stations[p].pb(c);
        vals.pb(c);
    }

    vals.pb(0);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    S = vals.size();

    tree[0] = {0, 0, 0, 0};
    root[1] = 0;
    dfs(1, 1);

    while (q--) {
        int u, v;
        int x, y;
        cin >> u >> v >> x >> y;
        int lca = get_lca(u, v);
        int tst = tree[root[u]].cnt + tree[root[v]].cnt - 2 * tree[root[lca]].cnt;
        int sst = walk(root[u], root[v], root[lca], 1, S, y);
        int vang = tst - sst;
        if (vang > x) {
            cout << -1 << el;
        } else {
            cout << x - vang << el;
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