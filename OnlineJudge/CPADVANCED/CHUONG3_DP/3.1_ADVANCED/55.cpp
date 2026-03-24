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
// Created: 2026-03-23 16:39

constexpr ll INF = 4e18;
constexpr ll LINF = 4e18;

#define FILENAME "55"

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

const int MAXN = 30 + 5;

ll dp[31][31];

void testcase() {
    int n, m;
    for(int n = 0; n <= 30; n++)
        for(int m = 0; m <= 30; m++) dp[n][m] = INF;

    for(int m = 0; m <= 30; m++) dp[0][m] = 0;
    for(int m = 0; m <= 30; m++) dp[1][m] = 1;
    for(int n = 1; n <= 30; n++)
    {
        if(n < 64) dp[n][3] = (1ULL << n) - 1;
    }

    for(int m = 4; m <= 30; m++)
    {
        for(int n = 2; n <= 30; n++)
        {
            for(int k = 1; k < n; k++)
            {
                dp[n][m] = min(dp[n][m], 2 * dp[k][m] + dp[n-k][m-1]);
            }
        }   
    }
    while (cin >> n >> m) {
        cout << dp[n][m] << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}