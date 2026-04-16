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
// Created: 2026-04-15 20:43

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "HELI"

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
vector<int> id(MAXN, 0);
vector<int> deg(MAXN, 0);

vector<int> low(MAXN, 0), num(MAXN, 0);
vector<bool> del(MAXN, false);
stack<int> tarjan;
int scc = 0;

int timeDfs = 0;
void dfs(int u) {
    low[u] = num[u] = ++timeDfs;
    tarjan.push(u);
    for (int v : g[u]) {
        if (del[v]) continue;
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        ++scc;
        int v;
        do {
            v = tarjan.top();
            tarjan.pop();
            del[v] = true;
            id[v] = scc;
        } while (v != u);
    }
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!num[i]) dfs(i);
    }
    for (int u = 1; u <= n; u++) {
        for (const int &v : g[u]) {
            if (id[v] != id[u]) {
                ++deg[id[v]];
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= scc; i++) {
        if (deg[i] == 0) ++res;
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