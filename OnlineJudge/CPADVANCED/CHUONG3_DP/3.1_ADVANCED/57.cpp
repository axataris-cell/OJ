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
// Created: 2026-04-02 16:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "57"

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

    vector<int> dp(n + 1, INF);
    vector<int> pre(n + 1, -1);

    dp[0] = 0;

    for (int i = 1; i * i <= n; i++) {
        int sq = i * i;
        for (int x = sq; x <= n; x++) {
            if (dp[x - sq] + 1 < dp[x]) {
                dp[x] = dp[x - sq] + 1;
                pre[x] = sq;
            }
        }
    }

    vector<int> res;
    int cur = n;
    while (cur > 0) {
        res.pb(pre[cur]);
        cur -= pre[cur];
    }

    sort(rall(res));

    for (int x : res) {
        cout << (int)sqrt(x) << ' ';
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