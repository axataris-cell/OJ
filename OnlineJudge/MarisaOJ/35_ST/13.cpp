#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 21:45

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

#define int long long

const int MAXN = 1e5 + 5;

struct Node {
    int sum, pref, suff, bestsum;
    int lazy;
    bool tag;

    Node() {
        sum = pref = suff = bestsum = 0;
        lazy = 0;
        tag = false;
    }
};

vector<int> a(MAXN, 0);
vector<Node> ST(4 * MAXN);

Node mergeNode(const Node &L, const Node &R) {
    if (L.pref == -LINF) return R;
    if (R.pref == -LINF) return L;

    Node res;
    res.sum = L.sum + R.sum;
    res.pref = max(L.pref, L.sum + R.pref);
    res.suff = max(R.suff, R.sum + L.suff);
    res.bestsum = max({L.bestsum, R.bestsum, L.suff + R.pref});
    return res;
}

void apply(int id, int l, int r, int val) {
    int len = r - l + 1;

    ST[id].sum = val * len;

    if (val >= 0) {
        ST[id].pref = ST[id].suff = ST[id].bestsum = ST[id].sum;
    } else {
        ST[id].pref = ST[id].suff = ST[id].bestsum = 0;
    }

    ST[id].lazy = val;
    ST[id].tag = true;
}

void push(int id, int l, int r) {
    if (!ST[id].tag) return;

    int mid = (l + r) / 2;

    apply(id << 1, l, mid, ST[id].lazy);
    apply(id << 1 | 1, mid + 1, r, ST[id].lazy);

    ST[id].tag = false;
}

void build(int id, int l, int r) {
    if (l == r) {
        ST[id].bestsum = ST[id].pref = ST[id].suff = ST[id].sum = a[l];
        ST[id].lazy = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int ql, int qr, int val) {
    if (qr < l || r < ql) return;

    if (ql <= l && r <= qr) {
        apply(id, l, r, val);
        return;
    }

    push(id, l, r);

    int mid = (l + r) / 2;

    update(id << 1, l, mid, ql, qr, val);
    update(id << 1 | 1, mid + 1, r, ql, qr, val);

    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

Node query(int id, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        Node res;
        res.sum = 0;
        res.pref = res.suff = res.bestsum = -LINF;
        return res;
    }

    if (ql <= l && r <= qr) return ST[id];

    push(id, l, r);

    int mid = (l + r) / 2;

    Node L = query(id << 1, l, mid, ql, qr);
    Node R = query(id << 1 | 1, mid + 1, r, ql, qr);

    return mergeNode(L, R);
}

void testcase() {
    int n, q; 
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r).bestsum << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1;
    while (t--) testcase();

    return 0;
}