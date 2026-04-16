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
// Created: 2026-04-16 16:37

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "M"

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

/*
+ gom BCC
+ dfs 2 lần cho cây BC (loại 1 & 2)
*/

const int MAXN = 1e5 + 5;

int n, m, k, l;

struct Edge {
    int v, id;
};

vector<Edge> g[MAXN];
vector<pii> edges(MAXN);
vector<int> tin(MAXN, 0), low(MAXN, 0);
stack<int> tarjan;
vector<int> bcc(MAXN, 0);
bool isBridge[MAXN];

vector<int> debug1[MAXN];

int bccCount = 0;
int timeDfs = 0;

bool istype0[MAXN], istype1[MAXN];

int res = 0;
vector<int> adj[MAXN]; // block cut tree
vector<vector<int>> dp(2, vector<int>(MAXN, 0));
bool vis[MAXN];

void tj(int u, int preid) {
    tin[u] = low[u] = ++timeDfs;
    tarjan.push(u);
    for (auto &[v, id] : g[u]) {
        if (id == preid) continue;
        if (!tin[v]) {
            tj(v, id);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]) isBridge[id] = true;
        } else {
            low[u] = min(low[u], tin[v]);
        }
    }
    if (tin[u] == low[u]) {
        int v;
        ++bccCount;
        do {
            v = tarjan.top();
            tarjan.pop();
            bcc[v] = bccCount;
            if (istype0[v]) ++dp[0][bccCount];
            if (istype1[v]) ++dp[1][bccCount];
        } while (u != v);
    }
}


void dfs(int u, int p) {    
    for (const int &v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[0][u] += dp[0][v];
        dp[1][u] += dp[1][v];
    }
    if (u != 1) {
        if (!dp[0][u] || !dp[1][u] || dp[0][u] == k || dp[1][u] == l) ++res;
    }
}

void testcase() {
    cin >> n >> m >> k >> l;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        istype0[x] = true;
    }
    for (int i = 1; i <= l; i++) {
        int x; cin >> x;
        istype1[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].fi >> edges[i].se;
        g[edges[i].fi].pb({edges[i].se, i});
        g[edges[i].se].pb({edges[i].fi, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) tj(i, -1);
    }

    for (int i = 1; i <= m; i++) {
        int u = bcc[edges[i].fi];
        int v = bcc[edges[i].se];
        if (u != v) {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
    
    dfs(1, 0);

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