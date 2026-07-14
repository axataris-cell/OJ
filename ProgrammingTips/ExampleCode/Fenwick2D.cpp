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
// Created: 2026-07-14 16:28

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Fenwick2D"

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

struct Fenwick2D {
    vector<vector<int>> bit;
    int n, m;

    Fenwick2D(int sz1, int sz2) : n(sz1), m(sz2), bit(sz1 + 1, vector<int>(sz2 + 1)) {}

    void update(int x, int yy, int val) {
        for (; x <= n; x += x & (-x)) {
            for (int y = yy; y <= m; y += y & (-y)) {
                bit[x][y] += val;
            }
        }
    }

    int query(int x, int yy) {
        int val = 0;
        for (; x > 0; x -= x & (-x)) {
            for (int y = yy; y > 0; y -= y & (-y)) {
                val += bit[x][y];
            }
        }
        return val;
    }
};

void testcase() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}