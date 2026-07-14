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
// Created: 2026-07-13 10:07

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TreeUVK"

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

const int MAXN = 2e5 + 5;

vector<pll> g[MAXN];
vector<ll> a(MAXN, 0);
vector<ll> ST(4 * MAXN, 0);

// void build(int id, int l, int r) {
//     if (l == r) {
//         ST[id] = a[l];
//         return;
//     }
//     int mid = (l + r) / 2;
//     build(id << 1, l, mid);
//     build(id << 1 | 1, mid + 1, r);
//     ST[id] = ST[id << 1] ^ ST[id << 1 | 1];
// }

void update(int id, int l, int r, int pos, ll val) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id << 1, l, mid, pos, val);
    else update(id << 1 | 1, mid + 1, r, pos, val);
    ST[id] = ST[id << 1] ^ ST[id << 1 | 1];
}

ll query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) ^ query(id << 1 | 1, mid + 1, r, ql, qr);
}

const int LOG = 30;

vector<int> tin(MAXN, 0);
vector<int> tout(MAXN, 0);
vector<vector<int>> par(LOG, vector<int>(MAXN, 1));
vector<int> h(MAXN, 0);
int timeDfs = 0;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    for (auto &[v, w] : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[0][v] = u;
        a[v] = w;
        dfs(v, u);
    }
    tout[u] = ++timeDfs;
}

void prep(int &n) {
    dfs(1, 1);
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) par[i][j] = par[i - 1][par[i - 1][j]];
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = (h[u] - h[v]);
        for (int i = 0; i < LOG; i++) {
            if (k >> i & 1) {
                u = par[i][u];
            }
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

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        int w; cin >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    prep(n);

    struct Dat {
        ll val, pos;
    };
    vector<Dat> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = {a[i + 1], i + 1};
    }
    sort(all(v), [](Dat x, Dat y) {
        return x.val < y.val;
    });

    struct Query {
        int x, y;
        ll k;
        int id;
    };
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].x >> queries[i].y >> queries[i].k;
        queries[i].id = i;
    }
    sort(all(queries), [](const Query &x, const Query &y) {
        return x.k < y.k;
    });
    vector<ll> ans(q);
    int cur = 0;
    for (int i = 0; i < q; i++) {
        auto &[x, y, k, id] = queries[i];
        while (cur < n && v[cur].val <= k) {
            update(1, 1, timeDfs, tin[v[cur].pos], v[cur].val);
            update(1, 1, timeDfs, tout[v[cur].pos], v[cur].val);
            ++cur;
        }
        if (h[x] < h[y]) swap(x, y);
        ans[id] = query(1, 1, timeDfs, 1, tin[x]) ^ query(1, 1, timeDfs, 1, tin[y]);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}