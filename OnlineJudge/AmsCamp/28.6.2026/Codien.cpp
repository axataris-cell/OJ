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
// Created: 2026-06-28 09:48

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "Codien"

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

const int MAXN = 5e5 + 5;

struct Node {
    int val; // normal sum
    int bestpref, bestsuf;
    int bestsum;
};

inline Node mergeNode(const Node &a, const Node &b) {
    Node res;

    res.val = a.val + b.val;

    res.bestpref = max(a.bestpref, a.val + b.bestpref);
    res.bestsuf = max(b.bestsuf, b.val + a.bestsuf);

    res.bestsum = max(max(a.bestsum, b.bestsum), a.bestsuf + b.bestpref);

    return res;
}

vector<int> a(MAXN, 0);
vector<Node> ST(4 * MAXN);

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

Node query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return {0, -LINF, -LINF, -LINF};
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return mergeNode(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr)); 
}

void testcase() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << query(1, 1, n, l, r).bestsum << el;
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