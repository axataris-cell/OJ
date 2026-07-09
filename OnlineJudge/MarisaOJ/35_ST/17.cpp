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
// Created: 2026-07-09 12:28

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "17"

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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

struct Node {
    int lz1, lz2;
    int val;
    Node() : val(0), lz1(0), lz2(0) {}
};

vector<Node> ST(4 * MAXN, Node());

void apply(int id, int l, int r, int a, int b) { // a is lz1, b is lz2
    ST[id].val += a * (r - l + 1) * (l + r) / 2 + b * (r - l + 1);
    ST[id].val %= MOD;
}

void push(int id, int l, int r) {
    if (!ST[id].lz1 && !ST[id].lz2) return;
    int a = ST[id].lz1;
    int b = ST[id].lz2;

    int mid = (l + r) / 2;
    ST[id << 1].lz1 += a;
    ST[id << 1].lz2 += b;
    apply(id << 1, l, mid, a, b);

    ST[id << 1 | 1].lz1 += a;
    ST[id << 1 | 1].lz2 += b;
    apply(id << 1 | 1, mid + 1, r, a, b);

    ST[id].lz1 = ST[id].lz2 = 0;
}

void update(int id, int l, int r, int ql, int qr, int a, int b) { // a = x, b = y - ql * x
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        apply(id, l, r, a, b);
        ST[id].lz1 += a;
        ST[id].lz2 += b;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr, a, b);
    update(id << 1 | 1, mid + 1, r, ql, qr, a, b);
    ST[id].val = ST[id << 1].val + ST[id << 1 | 1].val;
    ST[id].val %= MOD;
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return (ST[id].val % MOD);
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    return (query(id << 1, l, mid, ql, qr) % MOD + query(id << 1 | 1, mid + 1, r, ql, qr) % MOD) % MOD;
}

void testcase() {
    int n, q; cin >> n >> q;
    while (q--) {
        int t ; cin >> t;
        if (t == 1) {
            int l, r, x, y; cin >> l >> r >> x >> y;
            update(1, 1, n, l, r, x, y - l * x);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << el;
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