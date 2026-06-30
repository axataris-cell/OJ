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
// Created: 2026-06-25 09:04

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "NEARSET"

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

const int MAXN = 1e5 + 5;

vector<int> xc(MAXN, 0);
vector<int> yc(MAXN, 0);

void testcase() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> xc[i] >> yc[i];
    }
    vector<vector<bool>> vis(1000, vector<bool>(1000, false));
    int res = 0;
    int cur = 0;
    while (true) {
        pii best = {-INF, -INF};
        int mn = INF;
        for (int x = -100; x <= 100; x++) {
            for (int y = -100; y <= 100; y++) {
                if (vis[x + 100][y + 100]) continue;
                int sum = 0;
                for (int i = 1; i <= n; i++) {
                    sum += abs(xc[i] - x) + abs(yc[i] - y);
                }
                if (mn > sum) {
                    best = {x, y};
                    mn = sum;
                }
            }
        }
        if (cur + mn <= k) {
            cur += mn;
            vis[best.fi + 100][best.se + 100] = true;
            ++res;
        } else break;
    }
    cout << res;
    return;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}