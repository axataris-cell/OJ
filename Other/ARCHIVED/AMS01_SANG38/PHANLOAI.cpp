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
// Created: 2026-08-03 08:53

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "PHANLOAI"

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

ll res[4];

void testcase() {
    ll a, b, x, y; cin >> a >> b >> x >> y;
    res[1] = max(min(x, b + 1LL) - a, 0LL);
    res[3] = max(b - max(y, a - 1LL), 0LL);
    ll inner = max(a, x);
    ll outer = min(b, y);
    res[2] = max(outer - inner + 1, 0LL);

    ll mx = max({res[1], res[2], res[3]});
    for (int i = 1; i <= 3; i++) {
        if (res[i] == mx) {
            cout << i << ' ';
            break;
        }
    }
    cout << mx;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}