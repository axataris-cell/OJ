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
// Created: 2026-03-25 14:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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
const int LOG = 30;

// thuat trau
int n, m;

vector<int> g[MAXN];
vector<int> h(MAXN, 0);
vector<int> par(MAXN, 0);
vector<int> order;

void dfs(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
    }
}

void add(int u, int v, map<pii, int> &mp) {
    if (h[u] < h[v]) swap(u, v);
    while (h[u] != h[v]) {
        ++mp[{u, par[u]}];
        u = par[u];
    }
    if (u == v) return;
    while (u != v) {
        ++mp[{u, par[u]}];
        ++mp[{v, par[v]}];
        u = par[u];
        v = par[v];
    }
}
void testcase() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 1; i <= m; i++) {
        int x; cin >> x; //event
        order.pb(x);
    }
    dfs(1, 1);
    for (int u = 1; u <= n; u++) {
        map<pii, int> mp;
        int cur = u;
        for (auto v : order) {
            add(cur, v, mp);
            cur = v;
        }
        bool ok = true;
        for (auto [k, v] : mp) {
            // cerr << k.first << ' ' << k.second << ' ' << v << el;
            if (v > 2) {
                ok = false;
            }
        }
        cout << (ok ? 1 : 0) << el;
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