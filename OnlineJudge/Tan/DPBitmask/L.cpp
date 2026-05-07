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
// Created: 2026-05-06 20:45

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "L"

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

const int MOD = 1e9 + 7;

ll binpow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void testcase() {
    int n, m, k; cin >> m >> n >> k; // m dòng

    vector<ll> dp(16, 0);

    for (int c = 0; c < 4; ++c) {   
        dp[1 << c] = 1;
    }

    for (int col = 2; col <= n; ++col) {
        vector<ll> ndp(16, 0);
        for (int mask = 1; mask < 16; ++mask) {
            if (dp[mask] == 0) continue;
            
            for (int c = 0; c < 4; ++c) {
                int next_mask = mask | (1 << c);
                ndp[next_mask] = (ndp[next_mask] + dp[mask]) % MOD;
            }
        }
        dp = ndp;
    }

    ll res = 0;
    for (int mask = 1; mask < 16; ++mask) {
        if (__builtin_popcount(mask) >= k) {
            res = (res + dp[mask]) % MOD;
        }
    }

    cout << binpow(res, m);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}