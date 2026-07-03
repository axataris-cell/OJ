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
// Created: 2026-07-03 08:44

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "GiaoDichLienHoan"

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

void testcase() {
    int n, m; cin >> n >> m;

    vector<int> g[n + 1];
    vector<int> p(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        ++deg[b];
    }
    
    vector<int> topo;
    vector<int> dp(n + 1);

    {
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            dp[i] = p[i];
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        while (q.size()) {
            int u = q.front(); q.pop();
            topo.pb(u);
            for (auto v : g[u]) {
                if (--deg[v] == 0) q.push(v);
            }
        }
    }


    for (auto u : topo) {
        for (auto v : g[u]) {
            dp[v] = min(dp[v], dp[u]);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, p[i] - dp[i]);
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