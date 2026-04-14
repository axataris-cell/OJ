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
// Created: 2026-04-14 19:48

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "7"

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
    int n; cin >> n;
    int q; cin >> q;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a.begin() + 1, a.end(), [](pii x, pii y) {
        return x.se < y.se;
    });
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + a[i].fi;
    }
    while (q--) {
        int k; cin >> k;
        k = lower_bound(f.begin() + 1, f.end(), k) - f.begin();
        cout << (k <= n && k >= 1 ? a[k].se : -1) << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}