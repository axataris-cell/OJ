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
// Created: 2026-05-06 11:30

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "J"

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
    int k, r; cin >> k >> r;
    int m; cin >> m;
    bitset<105> reach[m];
    vector<pii> restaurant, pos;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        restaurant.pb({a, b});
    }
    int n; cin >> n;
    vector<int> amount(n, 0);
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        pos.pb({a, b});
        cin >> amount[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            auto [x1, y1] = restaurant[i];
            auto [x2, y2] = pos[j];
            if (hypot(float(abs(x2 - x1)), float(abs(y2 - y1))) <= float(r)) {
                reach[i][j] = true;
            }
        }
    }
    vector<int> validmask;
    for (int mask = 0; mask < (1 << m); mask++) {
        if (__builtin_popcount(mask) == k) validmask.pb(mask);
    }

    int res = 0;

    for (const auto &mask : validmask) {
        bitset<105> hop;
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) hop |= reach[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (hop[i]) cnt += amount[i];
        }
        res = max(res, cnt);
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}