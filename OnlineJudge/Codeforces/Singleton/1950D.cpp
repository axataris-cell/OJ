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
// Created: 2026-08-06 12:05

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1950D"

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

const int MAXN = 1e5 + 5;

vector<bool> dp(MAXN + 1, false);
vector<int> candy;

void testcase() {
    int n; cin >> n;

    cout << (dp[n] ? "YES" : "NO") << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    for (int mask = 0; mask < (1 << 5); mask++) {
        if (mask == 0 || mask == 1) continue;
        int num = 0;
        int cur = 1;
        for (int i = 0; i < 5; i++) {
            if (mask >> i & 1) {
                num += cur;
            }
            cur *= 10;
        }
        candy.pb(num);
        if (num <= MAXN) dp[num] = true;
    }
    dp[1] = true;
    for (int i = 1; i <= MAXN; i++) {
        for (auto x : candy) {
            if (i % x == 0) {
                dp[i] = dp[i] || dp[i / x];
            }
        }
    }

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}