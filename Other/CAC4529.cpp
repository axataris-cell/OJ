#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 07:54

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 1e5 + 5;
const int LOG = 31;

vector<int> a(MAXN, 0), f(MAXN, 0);
vector<vector<int>> dp(LOG, vector<int>(MAXN, INF));

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    for (int lg = LOG - 1; lg >= 0; lg--) dp[lg][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int lg = LOG - 1; lg >= 0; lg--) {
            int target = f[i] - (1 << lg);
            auto it = lower_bound(f.begin(), f.begin() + i, target) - f.begin();
            // cout << lg << ' ' << i << ' ' << it << el;
            if (it == i || f[it] != target) {
                continue;
            }
            for (int l = 0; l < LOG; l++) {
                dp[lg][i] = min(dp[lg][i], dp[l][it] + 1);
            }
        }
    }

    int res = INF;
    for (int lg = 0; lg < LOG; lg++) {
        res = min(res, dp[lg][n]);
    }

    // for (int lg = 0; lg < LOG; lg++) {
    //     for (int i = 1; i <= n; i++) cout << dp[lg][i] << ' ';
    //     cout << el;
    // }

    if (res != INF) cout << res;
    else cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}