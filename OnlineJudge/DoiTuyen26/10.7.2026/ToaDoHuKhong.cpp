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
// Created: 2026-07-10 11:16

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ToaDoHuKhong"

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

pll twoandfive(int v) {
    int cnt2 = 0;
    int cnt5 = 0;
    while (v > 0 && v % 2 == 0) {
        ++cnt2;
        v /= 2;
    }
    while (v > 0 && v % 5 == 0) {
        ++cnt5;
        v /= 5;
    }
    return {cnt2, cnt5};
}

const int MAXN = 1005;

vector<int> g[MAXN];

void testcase() {
    int n, m; cin >> n >> m;
    vector<int> val(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        ++deg[b];
    }

    vector<int> topo;
    vector<pll> dp(n + 1, {-1, -1});
    queue<int> q;

    q.push(1);
    dp[1] = twoandfive(val[1]);

    while (q.size()) {
        int u = q.front();q.pop();
        topo.pb(u);
        for (int v : g[u]) {
            if (--deg[v] == 0) {
                q.push(v);
            }
        }
    }

    for (auto u : topo) {
        for (auto v : g[u]) {
            pll cur = twoandfive(val[v]);
            pll ndp = {cur.fi + dp[u].fi, cur.se + dp[u].se};
            if (min(ndp.fi, ndp.se) > min(dp[v].fi, dp[v].se)) {
                dp[v] = ndp;
            } else if (min(ndp.fi, ndp.se) == min(dp[v].fi, dp[v].se)) {
                if (max(ndp.fi, ndp.se) > max(dp[v].fi, dp[v].se)) {
                    dp[v] = ndp;
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i].fi << ' ' << dp[i].se << el;
    // }

    cout << min(dp[n].fi, dp[n].se);

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}