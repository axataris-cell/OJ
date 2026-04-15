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
// Created: 2026-04-15 22:03

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "F"

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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> low(MAXN, 0), num(MAXN, 0);

int countBridge = 0;
map<pii, bool> isBridge;

int timeDfs = 0;
void bridge(int u, int p) {
    low[u] = num[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == p) continue;
        if (!num[v]) {
            bridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                ++countBridge;
                isBridge[{u, v}] = isBridge[{v, u}] = true;
            }
        } else low[u] = min(low[u], num[v]);
    }
}

bool vis[MAXN];
vector<pii> dp(MAXN, {0, 0}); // mx1 - mx2

void dfs(int u, int p) {
    vis[u] = true;
    for (const int &v : g[u]) {
        if (!vis[v]) {
            dfs(v, u);
            int k = isBridge[{u, v}];
            if (dp[v].fi + k > dp[u].fi) {
                dp[u].se = dp[u].fi;
                dp[u].fi = dp[v].fi + k;
            } else {
                if (dp[v].fi + k > dp[u].se) dp[u].se = dp[v].fi + k;
            }
        }
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    bridge(1, 1);
    dfs(1, 1);

    int maxCut = 0;
    for (int u = 1; u <= n; u++) {
        maxCut = max(maxCut, dp[u].fi + dp[u].se);
    }

    cout << countBridge - maxCut << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}