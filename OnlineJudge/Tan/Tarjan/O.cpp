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
// Created: 2026-04-18 17:44

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "O"

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

vector<int> g[MAXN];
vector<int> low(MAXN, 0);
vector<int> tin(MAXN, 0);
stack<int> tarjan;
bool del[MAXN];

vector<int> scc(MAXN, 0);
vector<int> money(MAXN, 0);
vector<int> totalMoney(MAXN, 0); // total money at each scc
int sccCount = 0;

int timeDfs = 0;
void tj(int u) {
    tin[u] = low[u] = ++timeDfs;
    tarjan.push(u);
    for (const int &v : g[u]) {
        if (del[v]) continue;
        if (!tin[v]) {
            tj(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], tin[v]);
    }
    if (low[u] == tin[u]) {
        int v;
        ++sccCount;
        do {
            v = tarjan.top();
            tarjan.pop();
            scc[v] = sccCount;
            totalMoney[sccCount] += money[v];
            del[v] = true;
        } while (u != v);
    }
}

vector<int> dag[MAXN];
vector<int> deg(MAXN, 0); // only reachable from s
vector<int> dp(MAXN, 0); // dp on scc

int s, p;
vector<int> stopPoint;

void topo() {
    queue<int> q;
    q.push(scc[s]);
    dp[scc[s]] = totalMoney[scc[s]];
    while (q.size()) {
        int u = q.front(); q.pop();
        for (const int &v : dag[u]) {
            dp[v] = max(dp[v], dp[u] + totalMoney[v]);
            if (--deg[v] == 0) q.push(v);
        }
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++) {
        cin >> money[i];
    }
    cin >> s >> p;
    for (int i = 1; i <= p; i++) {
        int x; cin >> x;
        stopPoint.pb(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) tj(i);
    }

    for (int u = 1; u <= n; u++) {
        for (const int &v : g[u]) {
            if (scc[u] != scc[v]) {
                dag[scc[u]].pb(scc[v]);
            }
        }
    }
    {
        queue<int> q;
        vector<bool> vis(n + 1, false);
        q.push(scc[s]);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (const int &v : dag[u]) {
                ++deg[v];
                if (vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    topo();

    int res = 0;
    for (const int &v : stopPoint) {
        res = max(res, dp[scc[v]]);
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