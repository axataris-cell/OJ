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
};

Node mergeNode(const Node &x, const Node &y) {
    if (x.openCount == -1) return y;
    if (y.openCount == -1) return x;

    Node res;

    int created = min(x.openCount, y.closeCount);
    res.openCount = x.openCount + y.openCount - created;
    res.closeCount = y.closeCount + x.closeCount - created;
    res.cnt = x.cnt + y.cnt + 2 * created;

    return res;
}

const int MAXN = 2e5 + 5;

vector<Node> ST(4 * MAXN);

void build(int id, int l, int r, string &s) {
    if (l == r) {
        ST[id] = {0, 0, 0};
        if (s[l - 1] == '(') ++ST[id].openCount;
        else ++ST[id].closeCount;
        return; 
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid, s);
    build(id << 1 | 1, mid + 1, r, s);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

Node query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return {-1, 0, 0}; // xu ly
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return mergeNode(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void testcase() {
    string s; cin >> s;
    int n = s.size();
    build(1, 1, n, s);
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        Node bruh = query(1, 1, n, l, r);
        cout << bruh.cnt << el;
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