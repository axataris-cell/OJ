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
// Created: 2026-07-07 08:34

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "intersect"

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

#define int long long

struct LinePair {
    int l1, r1, l2, r2;
    int calcLen() const {
        vector<pii> a;
        a.push_back({l1, 1});
        a.push_back({l2, 1});
        a.push_back({r1, -1});
        a.push_back({r2, -1});
        sort(all(a));
        int cur = 0;
        int lastpos = -1;
        int res = 0;
        for (int i = 0; i < 4; i++) {
            if (cur >= 2 && lastpos != -1) res += a[i].fi - lastpos;
            lastpos = a[i].fi;
            cur += a[i].se;
        }
        return res;
    } // length is r - l
    int potential() const {
        if (calcLen() == 0) { // legnth IS r- l fk
            if (l1 > l2) return r2 - l1;
            else return r1 - l2;
        }
        return llabs(l2 - l1) + llabs(r2 - r1);
    }
    int mergeLen() const { // when r1 = l2 ...
        return llabs(l2 - l1) + llabs(r2 - r1);
    }
    bool operator ()(const LinePair &x, const LinePair &y) const {
        return x.potential() < y.potential();
    };
};

void testcase() {
    // LinePair x = {1, 5, 5, 7};
    // cout << x.potential() << ' ' << x.mergeLen() << el;
    // return;

    int n, k; cin >> n >> k;
    vector<LinePair> a(n);
    pqueue<LinePair, vector<LinePair>, LinePair> pq;
    int cur = 0;
    int step = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l1 >> a[i].r1 >> a[i].l2 >> a[i].r2;
        cur += a[i].calcLen();
        pq.push(a[i]);
    }

    if (cur >= k) {
        cout << 0;
        return;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << a[i].potential() << ' ' << a[i].calcLen() << el;
    // }
    // return;

    while (pq.size()) {
        LinePair x = pq.top(); pq.pop();
        // cout  << "DEBUG: " << x.l1 << ' ' << x.r1 << ' ' << x.l2 << ' ' << x.r2 << ' ' << x.potential() << el;
        int l = x.calcLen();
        if (l) {
            step += min(k - cur, x.potential());
            cur = cur + min(k - cur, x.potential());
        } else {
            step -= x.potential();
            if (x.l1 > x.l2) {
                swap(x.l1, x.l2);
                swap(x.r1, x.r2);
            }
            x.r1 = x.l2;
            // cout << "AFTER: " << x.l1 << ' ' << x.r1 << ' ' << x.l2 << ' ' << x.r2 << ' ' << x.mergeLen() << ' ' << step << ' ' << cur << el;
            step += min(k - cur, x.mergeLen());
            cur = cur + min(k - cur, x.mergeLen());
        }
        if (cur >= k) break;
    }

    // neu van thieu thi dich chuyen 2 cai
    if (cur < k) {
        int diff = k - cur;
        step += diff * 2;
    }

    cout << step;
}

/*
4 8
1 4 9 11
1 2 4 7
1 2 3 4
1 9 999 1000
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}