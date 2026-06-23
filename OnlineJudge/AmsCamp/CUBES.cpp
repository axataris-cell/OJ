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
// Created: 2026-06-18 14:28

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "CUBES"

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
    int n, m, k; cin >> n >> m >> k;
    vector<int> color[m + 1];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        color[x].pb(i);
    }
    int res = 0;
    for (int cc = 1; cc <= m; cc++) {
        int sz = color[cc].size();
        int j = 0;
        for (int i = 0; i < sz; i++) {
            while (color[cc][i] - color[cc][j] + 1 - (i - j + 1) > k) ++j;
            res = max(res, i - j + 1);
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