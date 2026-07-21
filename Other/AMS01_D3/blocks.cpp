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
// Created: 2026-07-14 11:17

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "blocks"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".inp", "w", stdout);
    }
}

#define int long long

void testcase() {
    int n, q; cin >> n >> q;
    vector<int> c(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        
        int res = 0;
        int cur = 0;
        vector<int> a = c;
        for (int i = l; i <= r; i++) {
            if (a[i] + cur >= x) continue;
            int diff = x - a[i] - cur;
            int k = (diff + 1) / 2;
            cur += k;
            res += (n - i + 1) * k;
        }
        cout << res << el;
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