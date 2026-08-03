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
// Created: 2026-08-03 08:57

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "KKHUYET"

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

ll calc(ll n, ll L) {
    if (n <= 0) return 0LL;
    return (ll)(((ll)(n - 1) / L) + 1LL);
}

void testcase() {
    ll A, B;
    ll K;
    cin >> A >> B >> K;

    ll L = 1;
    for (ll i = 2; i <= K; i++) {
        ll g = gcd(L, i);
        if (L > B / (i / g)) {
            L = B + 1;
            break;
        }
        L = L / g * i;
    }

    cout << calc(B, L) - calc(A - 1, L);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}