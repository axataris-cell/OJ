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
// Created: 2026-05-06 21:15

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "M"

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
    int n, m; ll p, C;
    cin >> n >> m >> p >> C;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a.begin() + 1, a.end());

    vector<int> S(m);
    for (int i = 0; i < m; ++i) cin >> S[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(1 << m, -LINF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int mask = 0; mask < (1 << m); ++mask) {
            if (dp[i - 1][mask] == -LINF) continue;

            dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);

            for (int j = 0; j < m; ++j) {
                if (i >= S[j]) {
                    ll diff = a[i] - a[i - S[j] + 1];
                    ll cur = p - diff * diff * C;
                    int next_mask = mask | (1 << j);
                    if (dp[i - S[j]][mask] != -LINF) {
                        dp[i][next_mask] = max(dp[i][next_mask], dp[i - S[j]][mask] + cur);
                    }
                }
            }
        }
    }

    cout << dp[n][(1 << m) - 1] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1;
    while (t--) testcase();

    return 0;
}