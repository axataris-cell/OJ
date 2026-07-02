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
// Created: 2026-06-30 08:59

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "FDIGIT"

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
    int a, b; cin >> a >> b;
    int l = a;
    int r = b;
    while ((l % 9) != 1) --l;
    while ((r % 9) != 0) ++r;

    int res = (r - l + 1) * 5;

    while (l < a) {
        if (l % 9 == 0) res -= 9;
        else res -= l % 9; 
        ++l;
    }
    while (r > b) {
        if (r % 9 == 0) res -= 9;
        else res -= r % 9;
        --r;
    }
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}