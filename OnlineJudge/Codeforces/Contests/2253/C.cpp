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
// Created: 2026-08-07 21:33

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "C"

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
    int n, m, x, y; 
    cin >> n >> m >> x >> y;
    
    vector<int> a(x + 1, 0), b(y + 1, 0);
    for (int i = 1; i <= x; i++) cin >> a[i];
    for (int j = 1; j <= y; j++) cin >> b[j];

    vector<pll> elements;
    int p = x, q = y;

    while (p >= 1 || q >= 1) {
        if (p >= 1 && q >= 1 && a[p] == b[q]) {
            elements.pb({a[p], 3});
            p--;
            q--;
        } else if (q < 1 || (p >= 1 && a[p] > b[q])) {
            elements.pb({a[p], 1});
            p--;
        } else {
            elements.pb({b[q], 2});
            q--;
        }
    }

    int res = 0;
    int cntA = 0, cntB = 0;
    int total = 0;
    int limit = n + m - 1;

    for (auto &[val, type] : elements) {
        if (total == limit) break;

        if (type == 3) {
            res += val;
            total++;
        } else if (type == 1) {
            if (cntA < n) {
                res += val;
                cntA++;
                total++;
            }
        } else if (type == 2) {
            if (cntB < m) {
                res += val;
                cntB++;
                total++;
            }
        }
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}