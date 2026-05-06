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
// Created: 2026-05-06 14:37

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "K"

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
    vector<pii> songs(n);

    int cnt1 = 0;
    int cnt2 = 0;
    map<string, int> id1, id2;
    for (int i = 0; i < n; i++) {
        string s, t; cin >> s >> t;
        if (!id1.count(s)) id1[s] = ++cnt1;
        if (!id2.count(t)) id2[t] = ++cnt2;
        songs[i] = {id1[s], id2[t]};
    }

    vector<vector<bool>> dp(1 << n, vector<bool>(n, false));

    int res = INF;

    for (int i = 0; i < n; i++) dp[0][i] = true;
    for (int i = 0; i < n; i++) dp[1 << i][i] = true;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!((mask >> i) & 1)) continue;
            for (int j = 0; j < n; j++) {
                if (!((mask >> j) & 1) || i == j) continue;
                if (dp[mask ^ (1 << i)][j] && (songs[i].fi == songs[j].fi || songs[i].se == songs[j].se)) {
                    dp[mask][i] = true;
                    break;
                }
            }
            if (dp[mask][i]) res = min(res, n - __builtin_popcount(mask));
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