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
// Created: 2026-04-02 15:26

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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    vector<vector<int>> par(n + 1, vector<int>(m + 1, -1));

    for (int i = 1; i <= n; i++) {
        if (a[i] > m) continue;
        if (a[i] == m) {
            cout << 1 << el << i;
            return;
        }
        dp[i][a[i]] = 1;
        for (int s = 1; s <= m; s++) {
            for (int j = 1; j < i; j++) {
                if (s - a[j] > 0) continue;
            }
        }
    }

    int res = INF;
    int curidx = -1;
    int curwei = m;
    for (int i = 1; i <= n; i++) {
        if (res > dp[i][m]) {
            res = dp[i][m];
            curidx = i;
        }
    }

    vector<int> path;
    while (curidx != -1) {
        path.pb(curidx);
        int w = curwei;
        curwei -= a[curidx];
        if (curwei < 0) break;
        curidx = par[curidx][w];
    }
    reverse(all(path));

    assert(res == path.size());

    cout << res << el;
    for (auto x : path) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}