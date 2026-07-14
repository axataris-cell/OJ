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
// Created: 2026-07-13 09:27

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "TruyVanCayCon"

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

const int MAXN = 2e5 + 5;

vector<int> g[MAXN];

struct Fenwick {
    vector<int> bit;
    int n;

    Fenwick(int sz) : n(sz), bit(sz + 1) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }

    int query(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & (-pos)) {
            res += bit[pos];
        }
        return res;
    }
};

vector<int> tin(MAXN, 0), tout(MAXN, 0);
int timeDfs = 1;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++timeDfs;
}

void testcase() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1);
    Fenwick BIT(timeDfs + 1);
    for (int i = 1; i <= n; i++) {
        BIT.update(tin[i], a[i]);
        BIT.update(tout[i], -a[i]);
    }
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            int delta = x - a[s];
            BIT.update(tin[s], x - a[s]);
            BIT.update(tout[s], a[s] - x);
            a[s] = x;
        } else {
            int s; cin >> s;
            cout << BIT.query(tin[s]) << el;
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