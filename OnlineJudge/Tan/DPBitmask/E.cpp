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
// Created: 2026-05-05 20:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "E"

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
    int n; cin >> n;
    vector<vector<int>> a(8, vector<int>(n, 0));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    vector<vector<int>> dp(n + 1, vector<int>(256, -LINF));

    vector<int> valid_masks;
    for (int mask = 0; mask < (1 << 8); mask++) {
        bool ok = true;
        for (int i = 0; i < 7; i++) {
            if (((mask >> i) & 1) && ((mask >> (i + 1)) & 1)) ok = false;
        }
        if (ok) valid_masks.push_back(mask);
    }

    dp[0][0] = 0;

    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int mask : valid_masks) {
            int val = 0;
            for (int j = 0; j < 8; j++) if ((mask >> j) & 1) val += a[j][i - 1];

            for (int prev_mask : valid_masks) {
                if (mask & prev_mask) continue;
                if (dp[i-1][prev_mask] != -INF) {
                    dp[i][mask] = max(dp[i][mask], dp[i-1][prev_mask] + val);
                }
            }
            if (mask > 0) res = max(res, dp[i][mask]);
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