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
// Created: 2026-04-16 09:31

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "DOANDUONGPHU"

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

const int MAXN = 5e5 + 5;

struct Edge {
    int v, id;
};

vector<Edge> g[MAXN];
vector<pii> edges(MAXN, {0, 0});
vector<int> tin(MAXN, 0), low(MAXN, 0);
stack<int> tarjan;
vector<int> scc(MAXN, 0);

int sccCount = 0;
int timeDfs = 0;
void dfs(int u, int preID) {
    tin[u] = low[u] = ++timeDfs;
    tarjan.push(u);
    for (const auto &e : g[u]) {
        if (e.id == preID) continue;
        if (!tin[e.v]) dfs(e.v, e.id);
        low[u] = min(low[u], low[e.v]);
    }
    if (tin[u] == low[u]) {
        int v;
        ++sccCount;
        do {
            v = tarjan.top();
            tarjan.pop();
            scc[v] = sccCount;
        } while (u != v);
    }
}

int leaf = 0;
vector<int> treeadj[MAXN];

void dp(int u, int p) {
    int child = 0;
    for (int v : treeadj[u]) {
        if (v == p) continue;
        ++child;
        dp(v, u);
    }
    if (child == 0 && u != 1) {
        ++leaf;
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].fi >> edges[i].se;
        g[edges[i].fi].pb({edges[i].se, i});
        g[edges[i].se].pb({edges[i].fi, i});
    }
    for (int i = 1; i <= n; i++) {
        if (tin[i] == 0) dfs(i, -1);
    }
    for (int i = 1; i <= m; i++) {
        int u = scc[edges[i].fi], v = scc[edges[i].se];
        if (u != v) {
            treeadj[u].pb(v);
            treeadj[v].pb(u);
        }
    }
    dp(1, 0);
    if (treeadj[1].size() == 1) ++leaf;

    cout << (leaf + 1) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}