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
// Created: 2026-06-25 15:17

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "MUTATION"

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

const int MAXN = 3e5 + 5;

int n, q;
string s;

vector<int> ST(4 * MAXN, 0);
vector<int> lz(4 * MAXN, 0);

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void push(int id, int l, int r) {
    if (lz[id] == 0) return;

    int mid = (l + r) / 2;

    for (int i = 1; i <= lz[id]; i++) {
        ST[id << 1] *= 2;
        if (ST[id << 1] > 2e18) {
            ST[id << 1] = 2e18;
            break;
        }
    }
    lz[id << 1] += lz[id];


    for (int i = 1; i <= lz[id]; i++) {
        ST[id << 1 | 1] *= 2;
        if (ST[id << 1 | 1] > 2e18) {
            ST[id << 1 | 1] = 2e18;
            break;
        }
    }
    lz[id << 1 | 1] += lz[id];

    lz[id] = 0;
}

void updatePoint(int id, int l, int r, int pos, int val) {
    if (l == r) {
        if (ST[id] < 2e18) ST[id] += val;
        if (ST[id] > 2e18) ST[id] = 2e18;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    if (pos <= mid) updatePoint(id << 1, l, mid, pos, val);
    else updatePoint(id << 1 | 1, mid + 1, r, pos, val);

    if (ST[id << 1] + ST[id << 1 | 1] < 0 || ST[id << 1] + ST[id << 1 | 1] > 2e18) ST[id] = 2e18;
    else ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void updateRange(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        if (ST[id] < 2e18) ST[id] *= 2;
        if (ST[id] > 2e18) ST[id] = 2e18;
        ++lz[id];
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    updateRange(id << 1, l, mid, ql, qr);
    updateRange(id << 1 | 1, mid + 1, r, ql, qr);

    if (ST[id << 1] + ST[id << 1 | 1] < 0 || ST[id << 1] + ST[id << 1 | 1] > 2e18) ST[id] = 2e18;
    else ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    int l1 = query(id << 1, l, mid, ql, qr);
    int r1 = query(id << 1 | 1, mid + 1, r, ql, qr);
    if (l1 + r1 > 2e18 || l1 + r1 < 0) return 2e18;
    else return l1 + r1;
}

int find(int x) {
    int l = 1, r = n;
    int res = LINF;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (query(1, 1, n, 1, mid) < x) {
            l = mid + 1;
        } else {
            res = min(res, mid);
            r = mid - 1;
        }
    }
    return res;
}

void testcase() {
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    build(1, 1, n);

    // cout << find(2) << ' ' << find(3);
    // return;

    // query
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            // bs l on cur s
            int posl = find(l); // 1...n
            int posr = find(r);

            if (posl != posr) {
                int u = query(1, 1, n, 1, posl) - l + 1;
                int v = r - query(1, 1, n, 1, posr - 1);
                updatePoint(1, 1, n, posl, u);
                updatePoint(1, 1, n, posr, v);
            } else {
                updatePoint(1, 1, n, posl, r - l + 1);
            }
            if (posr - posl + 1 >= 3) {
                updateRange(1, 1, n, posl + 1, posr - 1);
            }
        } else {
            int x; cin >> x;
            // continue; //
            int pos = find(x);
            if (pos == LINF) cout << -1 << el;
            else cout << s[pos] << el;
        }
    }
    // for (int i = 1; i <= 6; i++) {
    //     cout << s[find(i)] << ' ';
    // }
    // cout << find(7);
}

/*
4 6
abac
2 2
2 3
1 2 3
2 3
2 4
2 6
*/

/*
1 64
a
1 1 1
1 1 2
1 1 4
1 1 8
1 1 16
1 1 32
1 1 64
1 1 128
1 1 256
1 1 512
1 1 1024
1 1 2048
1 1 4096
1 1 8192
1 1 16384
1 1 32768
1 1 65536
1 1 131072
1 1 262144
1 1 524288
1 1 1048576
1 1 2097152
1 1 4194304
1 1 8388608
1 1 16777216
1 1 33554432
1 1 67108864
1 1 134217728
1 1 268435456
1 1 536870912
1 1 1073741824
1 1 2147483648
1 1 4294967296
1 1 8589934592
1 1 17179869184
1 1 34359738368
1 1 68719476736
1 1 137438953472
1 1 274877906944
1 1 549755813888
1 1 1099511627776
1 1 2199023255552
1 1 4398046511104
1 1 8796093022208
1 1 17592186044416
1 1 35184372088832
1 1 70368744177664
1 1 140737488355328
1 1 281474976710656
1 1 562949953421312
1 1 1125899906842624
1 1 2251799813685248
1 1 4503599627370496
1 1 9007199254740992
1 1 18014398509481984
1 1 36028797018963968
1 1 72057594037927936
1 1 144115188075855872
1 1 288230376151711744
1 1 576460752303423488
1 1 1152921504606846976
1 1 2305843009213693952
1 1 4611686018427387904
2 48148989918
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}