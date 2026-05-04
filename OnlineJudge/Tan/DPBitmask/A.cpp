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
// Created: 2026-05-04 14:48

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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

void testcase() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>((1 << n) - 1, INF));

    for (int i = 0; i < n; i++) dp[i][1 << i] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!((mask >> i) & 1) || dp[i][mask] == INF) continue;
            for (int j = 0; j < n; j++) {
                if (!((mask >> j) & 1) || i == j) continue;
                dp[i][mask] = min(dp[i][mask], dp[j][mask - (1 << i)] + a[j][i]);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[i][(1 << (n + 1)) - 1]);
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