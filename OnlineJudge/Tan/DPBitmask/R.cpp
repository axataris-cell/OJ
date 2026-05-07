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
// Created: 2026-05-07 16:19

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "R"

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

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 6), b(n + 1, 6);
    for (int i = 2; i <= n; i++) {
        a[i] = (3 * a[i - 1] + 2 * b[i - 1]) % MOD;
        b[i] = (2 * a[i - 1] + 2 * b[i - 1]) % MOD;
    }
    cout << (a[n] + b[n]) % MOD;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}