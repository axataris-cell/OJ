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
// Created: 2026-04-01 09:15

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "prime"

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

ll prune(ll x) {
    ll res = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res *= i;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res *= x;
    return res;
}

void testcase() {
    ll x; cin >> x;

    ll s = sqrtl(x);
    ll ans = LINF;

    for (ll d = 0; d <= 100; d++) {
        for (ll sign = -1; sign <= 1; sign += 2) {
            ll t = s + sign * d;
            if (t <= 0) continue;

            ll sf = prune(t);
            ll y = sf * sf;

            ans = min(ans, llabs(x - y));
        }
    }

    cout << ans << el;

    multiset<int> st;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}
