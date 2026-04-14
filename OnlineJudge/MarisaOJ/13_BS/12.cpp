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
// Created: 2026-04-14 21:13

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "12"

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
    int n; ll s;
    cin >> n >> s;
    vector<ll> a(n + 1), p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    vector<ll> min_suf(n + 1);
    min_suf[n] = p[n];
    for (int i = n - 1; i >= 0; i--) {
        min_suf[i] = min(p[i], min_suf[i + 1]);
    }

    int res = -1;
    for (int i = 1; i <= n; i++) {
        ll target = s + p[i - 1];

        int l = i, r = n, pos = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (min_suf[mid] <= target) {
                pos = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        if (pos != -1) {
            res = max(res, pos - i + 1);
        }
    }

    cout << res << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}