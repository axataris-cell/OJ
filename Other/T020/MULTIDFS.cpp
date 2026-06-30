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
// Created: 2026-06-25 14:07

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "MULTIDFS"

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

const int MOD = 998244353;

void testcase() {
    int n, m; cin >> n >> m;
    vector<vector<int>> order(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> order[i][j];
        }
    }

    if (n == 1) {
        cout << 1;
        return;
    }

    // sub2
    if (m == 1) {
        int res = 1;
        for (int i = 1; i < n; i++) {
            res = (res * i) % MOD;
        }
        cout << res;
        return;
    }
    
    // sub 1

    vector<vector<bool>> par(n + 1, vector<bool>(n + 1, false));
    // i -> % par j
    par[1][1] = true;
    // khoi tao dp
    for (int i = 2; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            par[order[1][i]][order[1][j]] = true;
        }
    }
    for (int q = 2; q <= m; q++) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                par[order[q][i]][order[q][j]] = false;
            }
        }
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += (par[i][j] ? 1 : 0);
        }
        if (cnt != 0) res = (res * cnt) % MOD;
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