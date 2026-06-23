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
// #define len length
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-06-23 07:47

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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

const int MAXN = 5e5 + 5;
string base;

struct Node {
    int val;
    int len;
    int longest_suff;
    int longest_pref;
    int best;
};

Node mergeNode(const Node &a, const Node &b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    Node res;
    res.len = a.len + b.len;
    res.val = a.val + b.val;
    res.longest_suff = (b.longest_suff == b.len ? b.len + a.longest_suff : b.longest_suff);
    res.longest_pref = (a.longest_pref == a.len ? a.len + b.longest_pref : a.longest_pref);
    res.best = max({a.best, b.best, a.longest_suff + b.longest_pref});
    return res;
}
vector<Node> ST(4 * MAXN);

void build(int id, int l, int r) {
    ST[id].len = r - l + 1;
    if (l == r) {
        int v = base[l] - '0';
        ST[id].val = v;
        ST[id].longest_pref = ST[id].longest_suff = ST[id].best = v ^ 1;
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id].longest_pref = ST[id].longest_suff = ST[id].best = val ^ 1;
        ST[id].val = val;
        
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id << 1, l, mid, pos, val);
    else update(id << 1 | 1, mid + 1, r, pos, val);
    ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

Node query(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return {0, 0, 0, 0, 0};
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    return mergeNode(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void testcase() {
    int n, k; cin >> n >> k;
    cin >> base;
    base = " " + base;
    build(1, 1, n);
    // cout << ST[1].best << el;
    while (k--) {
        int x; cin >> x;
        int curv = base[x] - '0';
        update(1, 1, n, x, curv ^ 1);
        base[x] = (curv == 0 ? '1' : '0');
        cout << ST[1].best << el;
    }
    // cout << ST[1].best << ' ' << ST[1].len;
}

/*
6 1
001000
3
*/

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}