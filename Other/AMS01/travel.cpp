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
// Created: 2026-07-14 10:12

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "travel"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;

vector<int> g[MAXN];

void testcase() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    cout << 2 * (n - 1) - 2 << el;
    int res = 1;
    for (int i = 1; i < n; i++) {
        res = (res * i) % MOD;
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