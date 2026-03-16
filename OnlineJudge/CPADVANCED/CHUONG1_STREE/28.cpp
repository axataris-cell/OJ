#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 23:24

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 2e5 + 5;

int n, q;

vector<int> a(MAXN, 0);
vector<int> ST1(4 * MAXN, 0); //tăng
vector<int> ST2(4 * MAXN, 0); //giảm

void build1(int id, int l, int r) {
    if (l == r) {
        ST1[id] = a[l] + l;
        return;
    }
    int mid = (l + r) / 2;
    build1(id << 1, l, mid);
    build1(id << 1 | 1, mid + 1, r);

    ST1[id] = min(ST1[id << 1], ST1[id << 1 | 1]);
}

void build2(int id, int l, int r) {
    if (l == r) {
        ST2[id] = a[l] - l;
        return;
    }
    int mid = (l + r) / 2;
    build2(id << 1, l, mid);
    build2(id << 1 | 1, mid + 1, r);

    ST2[id] = min(ST2[id << 1], ST2[id << 1 | 1]);
}

void update1(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        ST1[id] = val + pos;
        return;
    }
    int mid = (l + r) / 2;
    update1(id << 1, l, mid, pos, val);
    update1(id << 1 | 1, mid + 1, r, pos, val);

    ST1[id] = min(ST1[id << 1], ST1[id << 1 | 1]);
}

void update2(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        ST2[id] = val - pos;
        return;
    }
    int mid = (l + r) / 2;
    update2(id << 1, l, mid, pos, val);
    update2(id << 1 | 1, mid + 1, r, pos, val);

    ST2[id] = min(ST2[id << 1], ST2[id << 1 | 1]);
}

int query1(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return INF;
    if (ql <= l && r <= qr) {
        return ST1[id];
    }
    int mid = (l + r) / 2;
    return min(query1(id << 1, l, mid, ql, qr), query1(id << 1 | 1, mid + 1, r, ql, qr));
}

int query2(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return INF;
    if (ql <= l && r <= qr) {
        return ST2[id];
    }
    int mid = (l + r) / 2;
    return min(query2(id << 1, l, mid, ql, qr), query2(id << 1 | 1, mid + 1, r, ql, qr));
}

int query(int pos) {
    int ans = a[pos];

    if (pos < n) ans = min(ans, query1(1, 1, n, pos + 1, n) - pos);
    if (pos > 1) ans = min(ans, query2(1, 1, n, 1, pos - 1) + pos);

    return ans;
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build1(1, 1, n);
    build2(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, val; cin >> x >> val;
            update1(1, 1, n, x, val);
            update2(1, 1, n, x, val);
            a[x] = val;
        } else {
            int x; cin >> x;
            cout << query(x) << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}