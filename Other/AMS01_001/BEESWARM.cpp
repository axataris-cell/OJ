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
// Created: 2026-06-30 08:49

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BEESWARM"

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
    vector<ll> a(55, 0);
    a[1] = 1;
    a[2] = 6;
    for (int i = 3; i < 55; i++) {
        a[i] = a[i - 1] * 2LL; 
        if (a[i] > 2e18) break;
    }
    vector<ll> f(55, 0);
    for (int i = 1; i < 55; i++) {
        f[i] = f[i - 1] + a[i];
        if (f[i] > 2e18) break;
    }

    ll n; cin >> n;
    int ok = upper_bound(all(f), n) - f.begin() - 1;
    cout << ok << el;
    cout << n - f[ok];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}