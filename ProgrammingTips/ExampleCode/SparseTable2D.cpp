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
// Created: 2026-07-14 16:01

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "SparseTable2D"

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

// max sparse tablet 2D
const int MAXN = 505;
const int LOG = 11;

int a[MAXN][MAXN];
int ST[LOG][LOG][MAXN][MAXN];

void build(int &n, int &m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ST[0][0][i][j] = a[i][j];
        }
    }

    for (int lg2 = 1; lg2 < LOG; lg2++) {
        for (int i = 1; i <= n; i++) { // lg1 = 0
            for (int j = 1; j + (1 << lg2) - 1 <= m; j++) {
                ST[0][lg2][i][j] = max(ST[0][lg2 - 1][i][j], ST[0][lg2 - 1][i][j + (1 << (lg2 - 1))]);
            }
        }
    }

    for (int lg1 = 1; lg1 < LOG; lg1++) {
        for (int i = 1; i + (1 << lg1) - 1 <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ST[lg1][0][i][j] = max(ST[lg1 - 1][0][i][j], ST[lg1 - 1][0][i + (1 << (lg1 - 1))][j]);
            }
        }
    }

    for (int lg1 = 1; lg1 < LOG; lg1++) {
        for (int lg2 = 1; lg2 < LOG; lg2++) {
            for (int i = 1; i + (1 << lg1) - 1 <= n; i++) {
                for (int j = 1; j + (1 << lg2) - 1 <= m; j++) {
                    ST[lg1][lg2][i][j] = max(ST[lg1][lg2 - 1][i][j], ST[lg1][lg2 - 1][i][j + (1 << (lg2 - 1))]);
                }
            }
        }
    }
}

int get(int x1, int y1, int x2, int y2) {
    int k = __lg(x2 - x1 + 1);
    int l = __lg(y2 - y1 + 1);
    return max({ST[k][l][x1][y1], ST[k][l][x2 - (1 << k) + 1][y1], ST[k][l][x1][y2 - (1 << l) + 1], ST[k][l][x2 - (1 << k) + 1][y2 - (1 << l) + 1]});
}

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    build(n, m);
    int q; cin >> q;
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << get(x1, y1, x2, y2) << el;
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