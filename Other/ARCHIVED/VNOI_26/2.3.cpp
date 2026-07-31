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
// Created: 2026-07-24 12:45

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "2.3"

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

struct Node {
    int mn, val;
};

struct SegmentTree {
    vector<Node> ST;
    int n;

    SegmentTree(int sz) : n(sz), ST(4 * sz + 1, {0, 0}) {}

    Node mergeNode(const Node &x, const Node &y) {
        Node res;
        res.val = x.val + y.val;
        res.mn = min(x.mn, y.mn);
        return res;
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            ST[id] = {val, val};
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);

        ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
    }

    Node query(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return {INF, 0};
        if (ql <= l && r <= qr) {
            return ST[id];
        }
        int mid = (l + r) / 2;
        return mergeNode(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
    }

    int walk(int id, int l, int r, int val) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (ST[id << 1].mn >= val) return walk(id << 1, l, mid, val);
        else return walk(id << 1 | 1, mid + 1, r, val);
    }
};

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    SegmentTree ST(n);

    umap<ll, int> mp;
    for (int i = 1; i <= n; i++) {
        int pos = ST.walk(1, 1, n, )
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