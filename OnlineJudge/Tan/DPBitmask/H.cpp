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
// Created: 2026-05-05 18:27

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "H"

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

const int MOD = 1e9 + 7;

void testcase() {
    int n; cin >> n;
    int m; cin >> m;

    vector<int> people[m + 1];

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        for (int j = 0; j < num; j++) {
            int x; cin >> x;
            people[x].pb(i);
        }
    }

    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[i - 1][mask] == 0) continue;

            dp[i][mask] += dp[i - 1][mask];
            dp[i][mask] %= MOD;

            for (const auto &p : people[i]) {
                if ((mask >> p) & 1) continue;
                int next_mask = mask | (1 << p);
                dp[i][next_mask] += dp[i - 1][mask];
                dp[i][next_mask] %= MOD;
            }
        }
    }

    cout << dp[m][(1 << n) - 1];

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}