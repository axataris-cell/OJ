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
// Created: 2026-04-14 19:53

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "8"

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
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n < 3) {
        cout << 0;
        return;
    }
    sort(a.begin() + 1, a.end());
    int res = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            int r = lower_bound(a.begin() + 1, a.begin() + j, a[j] + a[i]) - a.begin() - 1;
            int l = upper_bound(a.begin() + 1, a.begin() + j, abs(a[j] - a[i])) - a.begin();
            if (l <= r) {
                res += r - l + 1;
            }
        }
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