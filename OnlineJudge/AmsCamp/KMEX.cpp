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
// Created: 2026-06-18 13:39

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "kmex"

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
    int n, q; cin >> n >> q;
    vector<int> a(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = INF;
    sort(a.begin() + 1, a.end());
    while (q--) {
        int x; cin >> x;
        int l = 1, r = n;
        int v1 = -1, v2 = -1;
        // tim doan co the co dap an trong mang a
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = a[mid] - mid + 1;
            int val2 = a[mid + 1] - mid;
            if (val <= x && x <= val2) {
                v1 = val;
                v2 = val2;
                break;
            } else if () {

            } else if () {

            }
        }
        while (v1 <= v2) {
            int mid = (v1 + v2) / 2;
            int pos = lower_bound(a.begin() + 1, a.begin() + n + 1, mid) - a.begin() - 2;
            int cnt = mid - pos;
            if (cnt == x) {
                cout << mid << ' ';
                break;
            } else if (cnt < x) {
                v1 = mid + 1;
            } else if (cnt > x) {
                v2 = mid - 1;
            }
        }
    }
}

/*
4 1
1 2 6 7
1
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}