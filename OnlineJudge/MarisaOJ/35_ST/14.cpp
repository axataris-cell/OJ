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
// Created: 2026-07-07 19:45

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "14"

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

vector<int> a(MAXN, 0), b(MAXN, 0);

struct Node {
    int lz;
    int val;
};

vector<Node> ST(4 * MAXN);

Node mergeNode(const Node &l, const Node &r) {
    Node res;
    res.val = l.val + r.val;
    res.lz = INF;
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = {INF, b[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void push(int id, int l, int r) {
    if (ST[id].lz == INF || l == r) return;

    int mid = (l + r) / 2;
    if (l == mid) ST[id << 1].val = a[l + ST[id].lz];
    ST[id << 1].lz = ST[id].lz;

    if (mid + 1 == r) ST[id << 1 | 1].val = a[r + ST[id].lz];
    ST[id << 1 | 1].lz = ST[id].lz;

    ST[id].lz = INF;
}

void update(int id, int l, int r, int ql, int qr, int val) { // val is offset
    if (r < ql || l > qr) return;
    if (ql <= l && r <= qr) {
        if (l == r) {
            ST[id].val = a[l + val];
            ST[id].lz = INF;
        } else ST[id].lz = val;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr, val);
    update(id << 1 | 1, mid + 1, r, ql, qr, val);
}

int query(int id, int l, int r, int pos) {
    if (l == r) {
        return ST[id].val;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    if (pos <= mid) return query(id << 1, l, mid, pos);
    else return query(id << 1 | 1, mid + 1, r, pos);
}

void testcase() {
    int n; cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++)  {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    build(1, 1, n);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, k; cin >> x >> y >> k;
            update(1, 1, n, y, y + k - 1, x - y);
        } else {
            int i; cin >> i;
            cout << query(1, 1, n, i) << el;
        }
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