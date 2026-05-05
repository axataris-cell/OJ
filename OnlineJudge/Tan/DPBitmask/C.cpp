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
// Created: 2026-05-05 18:05

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> spec(n, vector<int>(n, 0));

    for (int i = 1; i <= k; i++) {
        int x, y, c; cin >> x >> y >> c;
        spec[x - 1][y - 1] = c;
    }

    vector<vector<int>> dp(n, vector<int>(1 << n, -LINF));

    for (int i = 0; i < n; i++) dp[i][1 << i] = a[i];

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!((mask >> i) & 1)) continue;
            for (int j = 0; j < n; j++) {
                int prev_mask = mask ^ (1 << i);
                if (!((mask >> j) & 1) || dp[j][prev_mask] == -LINF || i == j) continue;
                dp[i][mask] = max(dp[i][mask], dp[j][prev_mask] + a[i] + spec[i][j]);
            }
        }
    }

    int res = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int popcount = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) ++popcount;
        }
        if (popcount == m) {
            for (int i = 0; i < n; i++) {
                if (!((mask >> i) & 1)) continue;
                res = max(res, dp[i][mask]);
            }
        }
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