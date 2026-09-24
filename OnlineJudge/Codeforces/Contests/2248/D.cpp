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
// Created: 2026-08-05 17:35

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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
    int n, q; cin >> n >> q;
    string s[2];
    cin >> s[0] >> s[1];
    vector<vector<int>> cnt0(2, vector<int>(n + 1, 0)), cnt1(2, vector<int>(n + 1, 0));
    vector<vector<int>> cnt(1 << 2, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            cnt0[j][i] = cnt0[j][i - 1] + (s[j][i - 1] == '0');
            cnt1[j][i] = cnt1[j][i - 1] + (s[j][i - 1] == '1');
        }
        for (int mask = 0; mask < 1 << 2; mask++) cnt[mask][i] = cnt[mask][i - 1];
        cnt[((s[0][i - 1] - '0') << 1) + s[1][i - 1] - '0'][i]++;
    }

    auto domi0 = [&](int l, int r, int type) -> bool { // bien s thanh 0-domi
        int curcnt0 = cnt0[type][r] - cnt0[type][l - 1];
        int curcnt1 = cnt1[type][r] - cnt1[type][l - 1];
        int diff = curcnt1 - curcnt0;
        if (diff <= 0) return true;
        // try to use same type
        if (diff <= cnt[3][r] - cnt[3][l - 1]) return true;
        diff -= cnt[3][r] - cnt[3][l - 1];
        if (diff > cnt[3][r] - cnt[3][l - 1]) return false;
        int low = cnt1[type ^ 1][r] - cnt1[type ^ 1][l - 1] - (cnt[3][r] - cnt[3][l - 1]);
        int mxallow = cnt0[type ^ 1][r] - cnt0[type ^ 1][l - 1] - low;
        if (diff <= mxallow) return true;
        else return false;
    };

    auto domi1 = [&](int l, int r, int type) -> bool { // bien s thanh 0-domi
        int curcnt0 = cnt0[type][r] - cnt0[type][l - 1];
        int curcnt1 = cnt1[type][r] - cnt1[type][l - 1];
        int diff = curcnt0 - curcnt1;
        if (diff <= 0) return true;
        // try to use same type
        if (diff <= cnt[0][r] - cnt[0][l - 1]) return true;
        diff -= cnt[0][r] - cnt[0][l - 1];
        if (diff > cnt[0][r] - cnt[0][l - 1]) return false;
        int low = cnt0[type ^ 1][r] - cnt0[type ^ 1][l - 1] - (cnt[0][r] - cnt[0][l - 1]); // sau khi doi cung
        int mxallow = cnt1[type ^ 1][r] - cnt1[type ^ 1][l - 1] - low;
        if (diff <= mxallow) return true;
        else return false;
    };

    while (q--) {
        int l, r; cin >> l >> r;
        if (domi0(l, r, 0) && domi0(l, r, 1)) {
            cout << "YES" << el;
            continue;
        }
        if (domi1(l, r, 0) && domi1(l, r, 1)) {
            cout << "YES" << el;
            continue;
        }
        cout << "NO" << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}