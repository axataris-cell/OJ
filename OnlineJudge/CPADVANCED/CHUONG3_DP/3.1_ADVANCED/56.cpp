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
// Created: 2026-03-23 17:02

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "56"

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
    int n, m; cin >> n >> m;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 2, vector<int>(m + 1, INF)); // so phan tu it nhat trong day con tong bang j cho den vi tri i
    vector<int> par(n + 1, -1); // truy vet
    for (int j = 1; j <= m; j++) {
        dp[1][j] = 0;
    }
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n + 1; i++) {
        for (int j = m; j >= 1; j--) {
            if (j - a[i] >= 0) dp[i][j] = dp[i][j], dp[i - 1][j - a[i]] + 1;
        }
    }

    if (dp[n+1][m] != INF) cout << dp[n + 1][m];
    else cout << -1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}