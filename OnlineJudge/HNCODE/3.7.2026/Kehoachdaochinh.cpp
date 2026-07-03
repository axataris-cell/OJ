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
// Created: 2026-07-03 10:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Kehoachdaochinh"

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

const int MAXN = 1e6 + 5;

vector<pii> g[MAXN];

void testcase() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    vector<int> req(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        req[v] |= (1 << u);
    }

    vector<vector<int>> W(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int u, v;
        int w;
        cin >> u >> v >> w;
        --u; --v;
        W[u][v] = w;
        W[v][u] = w;
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -LINF));

    for (int i = 0; i < n; i++) {
        if (req[i] == 0) {
            dp[1 << i][i] = R[i];
        }
    }

    for (int mask = 1; mask < 1 << n; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) || dp[mask][u] == -LINF) continue;

            for (int v = 0; v < n; v++) {
                if (!(mask & (1 << v))) {
                    if ((mask & req[v]) == req[v]) {
                        int nmask = mask | (1 << v);
                        dp[nmask][v] = max(dp[nmask][v], dp[mask][u] + R[v] - W[u][v]);
                    }
                }
            }
        }
    }
    
    int ans = -LINF;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[(1 << n) - 1][i]);
    }

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}