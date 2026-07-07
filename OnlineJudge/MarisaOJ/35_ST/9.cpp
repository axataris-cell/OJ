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
// Created: 2026-07-03 19:27

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "9"

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

const int MAXN = 1e5 + 5;

struct Node {
    int cnt0, cnt1, cnt2;
    int lz;
};

vector<Node> ST(4 * MAXN);
vector<int> a(MAXN, 0);

Node mergeNode(const Node &l, const Node &r) {
    Node res;
    res.cnt0 = l.cnt0 + r.cnt0;
    res.cnt1 = l.cnt1 + r.cnt1;
    res.cnt2 = l.cnt2 + r.cnt2;
    return res;
}

void push(int id, int l, int r) {
    if (!ST[id].lz) return;

    ST[id << 1].lz += ST[id].lz;
    if (ST[id].lz % 3 == 1) ST[id << 1] = {ST[id << 1].cnt2, ST[id << 1].cnt0, ST[id << 1].cnt1, ST[id << 1].lz};
    else if (ST[id].lz % 3 == 2) ST[id << 1] = {ST[id << 1].cnt1, ST[id << 1].cnt2, ST[id << 1].cnt0, ST[id << 1].lz};

    ST[id << 1 | 1].lz += ST[id].lz;
    if (ST[id].lz % 3 == 1) ST[id << 1 | 1] = {ST[id << 1 | 1].cnt2, ST[id << 1 | 1].cnt0, ST[id << 1 | 1].cnt1, ST[id << 1 | 1].lz};
    else if (ST[id].lz % 3 == 2) ST[id << 1 | 1] = {ST[id << 1 | 1].cnt1, ST[id << 1 | 1].cnt2, ST[id << 1 | 1].cnt0, ST[id << 1 | 1].lz};

    ST[id].lz = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        if (a[l] % 3 == 0) ST[id] = {1, 0, 0, 0};
        if (a[l] % 3 == 1) ST[id] = {0, 1, 0, 0};
        if (a[l] % 3 == 2) ST[id] = {0, 0, 1, 0};
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ++ST[id].lz;
        ST[id] = {ST[id].cnt2, ST[id].cnt0, ST[id].cnt1, ST[id].lz};
        return;
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    update(id << 1, l, mid, ql, qr);
    update(id << 1 | 1, mid + 1, r, ql, qr);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

Node query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return {0, 0, 0, 0};
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    push(id, l, r);
    int mid = (l + r) / 2;
    return mergeNode(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int t; cin >> t;
        int l, r; cin >> l >> r;
        if (t == 1) update(1, 1, n, l, r);
        else cout << query(1, 1, n, l, r).cnt0 << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}