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
// Created: 2026-07-24 09:20

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2"

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
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll res = 0;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int l = 1; l <= n; l++) {
        umap<int, int> mp;
        int cur = 0;
        int cnt1 = 0;
        int cnthole = 0;
        for (int r = l; r <= n; r++) {
            if (a[r] == -1) ++cnt1;
            else {
                if (a[r] < cur && mp[a[r]] == 0) --cnthole;
                ++mp[a[r]];
            }
            while (cnthole < cnt1 || mp[cur] > 0) {
                if (mp[cur] == 0) ++cnthole;
                ++cur;
            }
            res += cur;
            dp[l][r] = cur;
        }
    }
    for (int r = 1; r <= n; r++) {
        for (int l = 1; l <= r; l++) {
            cout << dp[l][r] << ' ';
        }
        cout << el; 
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}