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
// Created: 2026-08-06 21:39

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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
    string s; cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (char c : s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }

    int D = cnt0 - cnt1;

    if (abs(D) > 2) {
        cout << -1 << el;
        return;
    }

    int L0 = 0;
    char expected = '0';
    for (char c : s) {
        if (c == expected) {
            L0++;
            expected = (expected == '0') ? '1' : '0';
        }
    }

    int L1 = 0;
    expected = '1';
    for (char c : s) {
        if (c == expected) {
            L1++;
            expected = (expected == '0') ? '1' : '0';
        }
    }

    int mxlen = -1;

    if (D >= 0 && D <= 2) {
        if (L0 > 0) {
            int len = (L0 % 2 != 0) ? L0 : L0 - 1;
            mxlen = max(mxlen, len);
        }
    }

    if (D >= -2 && D <= 0) {
        if (L1 > 0) {
            int len = (L1 % 2 != 0) ? L1 : L1 - 1;
            mxlen = max(mxlen, len);
        }
    }

    if (D >= -1 && D <= 1) {
        if (L0 > 0) {
            int len = (L0 % 2 == 0) ? L0 : L0 - 1;
            mxlen = max(mxlen, len);
        }
    }

    if (D >= -1 && D <= 1) {
        if (L1 > 0) {
            int len = (L1 % 2 == 0) ? L1 : L1 - 1;
            mxlen = max(mxlen, len);
        }
    }

    if (D >= -1 && D <= 1) {
        mxlen = max(mxlen, 0);
    }

    if (mxlen == -1) {
        cout << -1 << el;
    } else {
        cout << n - mxlen << el;
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