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
// Created: 2026-04-03 14:53

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "HDIFF"

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

ll countPair(const vector<int>& a, int n, int diff) {
    ll cnt = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        while (a[r] - a[l] > diff) {
            l++;
        }
        cnt += (r - l);
    }
    return cnt;
}

void testcase() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(all(a));

    int l = 0;
    int r = a[n - 1] - a[0];
    int ans = r;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (countPair(a, n, mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}