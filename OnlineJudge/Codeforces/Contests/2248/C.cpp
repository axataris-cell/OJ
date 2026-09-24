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
// Created: 2026-08-05 16:26

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
    int n; cin >> n;
    vector<int> a(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    vector<int> dp(2 * n + 1, 0);
    vector<int> prev(2 * n + 1, -1);
    {
        vector<int> mp(n + 1, 0);
        for (int i = 1; i <= 2*n; i++) {
            if (mp[a[i]] == 0) {
                mp[a[i]] = i;
            } else prev[i] = mp[a[i]];
        }
    }
    // for (int i = 1; i <= 2 * n; i++) {
    //     cout << prev[i] << ' ';
    // }
    // return;
    for (int r = 1; r <= 2 * n; r++) {
        int l = prev[r];
        if (l == -1) dp[r] = dp[r - 1] + 1;
        else dp[r] = max(dp[l - 1] + (r - l + 1) * (r - l + 1), dp[r - 1] + 1);
    }

    cout << dp[2 * n] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}