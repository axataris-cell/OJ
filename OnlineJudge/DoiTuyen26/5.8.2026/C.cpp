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
// Created: 2026-08-05 09:24

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

struct Node {
    int openCount;
    int closeCount;
    int cnt;
    int openCount2;
    int closeCount2;
    int cnt2;
    int lz; // 1 0
};

Node mergeNode(const Node &x, const Node &y) {
    if (x.openCount == -1) return y;
    if (y.openCount == -1) return x;

    Node res;

    {
        int created = min(x.openCount, y.closeCount);
        res.openCount = x.openCount + y.openCount - created;
        res.closeCount = y.closeCount + x.closeCount - created;
        res.cnt = x.cnt + y.cnt + 2 * created;
    }

    {
        int created = min(x.openCount2, y.closeCount2);
        res.openCount2 = x.openCount2 + y.openCount2 - created;
        res.closeCount2 = y.closeCount2 + x.closeCount2 - created;
        res.cnt2 = x.cnt2 + y.cnt2 + 2 * created;
    }

    res.lz = 0;

    return res;
}

const int MAXN = 2e5 + 5;

vector<Node> ST(4 * MAXN);

void flip(int id, int l, int r) {
    swap(ST[id].openCount2, ST[id].openCount);
    swap(ST[id].closeCount2, ST[id].closeCount);
    swap(ST[id].cnt, ST[id].cnt2);
    ST[id].lz ^= 1;
}

void push(int id, int l, int r) {
    if (!ST[id].lz) return;

    int mid = (l + r) / 2;

    flip(id << 1, l, mid);
    flip(id << 1 | 1, mid + 1, r);

    ST[id].lz = 0;
    return;
}

void build(int id, int l, int r, string &s) {
    if (l == r) {
        ST[id] = {0, 0, 0, 0, 0, 0, 0};
        if (s[l - 1] == '(') {
            ++ST[id].openCount;
            ++ST[id].closeCount2;
        }
        else {
            ++ST[id].closeCount;
            ++ST[id].openCount2;
        }
        return; 
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid, s);
    build(id << 1 | 1, mid + 1, r, s);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        flip(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr);
    update(id << 1 | 1, mid + 1, r, ql, qr);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

Node query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return {-1, 0, 0, 0, 0, 0, 0}; // xu ly
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    return mergeNode(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void testcase() {
    int n; cin >> n;
    string s; cin >> s;
    build(1, 1, n, s);
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        int l, r; cin >> l >> r;
        if (t == 1) {
            Node bruh = query(1, 1, n, l, r);
            cout << bruh.cnt << el;
        } else {
            update(1, 1, n, l, r);
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