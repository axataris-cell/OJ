#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 15:04

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

vector<int> a(MAXN, 0);
vector<int> ST(4 * MAXN, 0);
vector<int> lz(4 * MAXN, 0), lzcnt(4 * MAXN, 0);

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void apply(int id, int l, int r, int val, int cnt) {
    ST[id] += cnt * (l + r) * (r - l + 1) / 2 - (val - cnt) * (r - l + 1);
    lz[id] += val; lzcnt[id] += cnt;
}

void push(int id, int l, int r) {
    if (lz[id] == 0 || lzcnt[id] == 0 || l == r) return;

    int mid = (l + r) / 2;

    apply(id << 1, l, mid, lz[id], lzcnt[id]);
    apply(id << 1 | 1, mid + 1, r, lz[id], lzcnt[id]);

    lz[id] = 0;
    lzcnt[id] = 0;
}

void update(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        apply(id, l, r, ql, 1);
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr);
    update(id << 1 | 1, mid + 1, r, ql, qr);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) update(1, 1, n, l, r);
        else cout << query(1, 1, n, l, r) << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}