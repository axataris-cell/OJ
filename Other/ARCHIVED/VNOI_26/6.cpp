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
// Created: 2026-07-24 12:36

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "6"

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
    int dx = 1;
    int dy = 1;

    int n, m; cin >> n >> m;
    int k, sx, sy; cin >> k >> sx >> sy;

    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));

    umap<int, int> mpval;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mpval[0]++;
        }
    }

    int cur = 0;

    auto upd = [&]() {
        while (mpval[cur] <= 0) ++cur;
    };

    auto clean = [&](int x, int y) {
        for (int i = 1; i <= n; i++) {
            if (i == x) continue;
            --mpval[a[i][y]];
            ++mpval[a[i][y] + 1];
            a[i][y]++;
        }
        for (int i = 1; i <= m; i++) {
            --mpval[a[x][i]];
            ++mpval[a[x][i] + 1];
            a[x][i]++;
        }
    };

    auto rotate = [&](int &x, int &y) {
        if (x + dx > n || x + dx <= 0) dx = -dx;
        if (y + dy > m || y + dy <= 0) dy = -dy;
        x = x + dx;
        y = y + dy;
    };

    int timer = -1;
    while (cur < k) {
        ++timer;
        clean(sx, sy);
        rotate(sx, sy);
        upd();
    }

    cout << timer << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}