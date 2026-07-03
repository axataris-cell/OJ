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
// Created: 2026-07-03 10:25

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "DayNuiLienThong"

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

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n), par(n) {}

    void make(int i) {
        sz[i] = 1;
        par[i] = i;
    }

    int find(int i) {
        return i == par[i] ? i : par[i] = find(par[i]);
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
    }
};

const int MAXN = 2e5 + 5;

vector<int> g[MAXN];
vector<int> comp[MAXN];
map<pii, bool> visEdge;

void testcase() {
    int n, m; cin >> n >> m;

    DSU dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.make(i);

    for (int i = 1; i <= m; i++) {
        int t, a, b; cin >> t >> a >> b;
        if (t == 2) dsu.join(a, b);
        else g[a].pb(b);
    }

    vector<int> deg(n + 1, 0); // comppressed
    for (int i = 1; i <= n; i++) {
        int g1 = dsu.find(i);
        for (int v : g[i]) {
            int g2 = dsu.find(v);
            if (!visEdge[{g1, g2}]) {
                comp[g2].pb(g1); // do thi nguoc
                ++deg[g1];
                visEdge[{g2, g1}] = true;
            }
        }
    }

    vector<int> topo;

    vector<bool> used(n + 1, false);
    vector<bool> group(n + 1, false);
    int groupcount = 0;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        int gi = dsu.find(i);
        group[gi] = true;
        if (!used[gi] && deg[gi] == 0) {
            q.push(gi);
            used[gi] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (group[i]) ++groupcount;
    }

    while (q.size()) {
        int u = q.front(); q.pop();
        topo.pb(u);
        for (int v : comp[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() != groupcount) {
        cout << -1;
        return;
    }

    vector<int> dp(n + 1, 1);
    for (auto u : topo) {
        for (auto v : comp[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[dsu.find(i)]);
    }

    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}