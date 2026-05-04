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
// Created: 2026-05-04 14:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2"

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
vector<int> g[MAXN];
vector<int> tin(MAXN, 0), tout(MAXN, 0);
vector<int> ST(4 * MAXN), lz(4 * MAXN);

int timeDfs = 0;
void dfs(int u, int p) {
    tin[u] = tout[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = timeDfs;
}

void push(int id, int l, int r) {
    if (lz[id] == 0) return;

    int mid = (l + r) / 2;

    ST[id << 1] += lz[id] * (mid - l + 1); 
    lz[id << 1] += lz[id];

    ST[id << 1 | 1] += lz[id] * (r - mid);
    lz[id << 1 | 1] += lz[id];

    lz[id] = 0;
}

void update(int id, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id] += (r - l + 1) * val;
        lz[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr, val);
    update(id << 1 | 1, mid + 1, r, ql, qr, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 1);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int v, x; cin >> v >> x;
            update(1, 1, n, tin[v], tout[v], x);
        } else {
            int u; cin >> u;
            cout << query(1, 1, n, tin[u], tin[u]) << el;
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