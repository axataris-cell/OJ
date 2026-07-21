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
// Created: 2026-07-21 08:41

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "migu"

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

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n <= 1000) {
        int res = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (a[i] * a[j] == i + j) ++res;
            }
        }

        cout << res << el;
        return;
    }
    set<pii> s;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        auto l = s.lower_bound({i / a[i] + 1, 0});
        while (l != s.end()) {
            pii k = *l;
            if (k.first >= (2 * i + a[i] - 1) / a[i]) break; //?
            if (a[i] * k.fi == k.se + i) ++res;
            l = next(l);
        }
        s.insert({a[i], i});
    }

    cout << res << el;
} 

/*
4
2
3 4
4 
1 3 2 4
6
2 1 5 8 3 4
10
11 12 13 14 15 16 17 18 19 20
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}