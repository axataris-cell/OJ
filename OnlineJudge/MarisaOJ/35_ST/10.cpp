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
// Created: 2026-07-06 16:40

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "10"

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

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int _n) : n(_n), bit(_n + 1) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }

    int query(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & (-pos)) res += bit[pos];
        return res;
    }
};

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> tin(MAXN, 0), tout(MAXN, 0);

int timeDfs = 0;

void dfs(int u, int p) {
    tin[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++timeDfs;
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, 1);
    FenwickTree BIT(timeDfs);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cout << BIT.query(tin[x]) << el;
        BIT.update(tin[x], 1);
        BIT.update(tout[x], -1);
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