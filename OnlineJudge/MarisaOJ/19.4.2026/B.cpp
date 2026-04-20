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
// Created: 2026-04-19 22:05

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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
    ll L, R;
    cin >> L >> R;

    ll M = L - 1;
    ll max_gcd = 1;

    for (ll l = 1, r; l <= R; l = r + 1) {
        ll v1 = R / l;
        if (v1 == 0) {
            r = R;
        } else {
            r = R / v1;
        }

        ll v2 = 0;
        if (l <= M) {
            v2 = M / l;
            if (v2 > 0) {
                r = min(r, M / v2);
            }
        }

        if (v1 - v2 >= 2) {
            max_gcd = max(max_gcd, r);
        }
    }

    cout << max_gcd << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}