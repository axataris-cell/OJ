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
#define el '\n'

// Author: Axataris
// Created: 2026-04-03 14:00

constexpr int INF = 2e9;

#define FILENAME "MSPAIR"

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
#define LINF 4e18

void testcase() {
    ll m, n; cin >> m >> n;

    if (n % m != 0) {
        cout << -1 << el;
        return;
    }

    ll k = n / m;
    ll res = LINF;

    for (ll x = 1; x * x <= k; x++) {
        if (k % x == 0) {
            ll y = k / x;
            if (__gcd(x, y) == 1) {
                res = min(res, m * (x + y));
            }
        }
    }

    cout << (res == LINF ? -1 : res) << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}