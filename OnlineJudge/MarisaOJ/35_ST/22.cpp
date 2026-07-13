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
// Created: 2026-07-11 16:12

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "22"

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

string s;

struct SegmentTree { 
    struct Node {
        int val;
        int lz;
        Node() : lz(-1), val(0) {}
        Node operator + (const Node &other) const {
            Node res = Node();
            res.val = val + other.val;
            return res;
        }
    };

    int n;
    char stat;
    vector<Node> ST;

    SegmentTree(int sz) : n(sz), ST(4 * sz + 1, Node()) {}

    void apply(int id, int l, int r, int type) {
        ST[id].val = (r - l + 1) * type;
        ST[id].lz = type;
    }

    void push(int id, int l, int r) {
        if (ST[id].lz == -1) return;

        int mid = (l + r) / 2;

        apply(id << 1, l, mid, ST[id].lz);
        apply(id << 1 | 1, mid + 1, r, ST[id].lz);

        ST[id].lz = -1;
    }

    void build(int id, int l, int r) {
        if (l == r) {
            ST[id].val = (s[l] == stat);
            return;
        }
        int mid = (l + r) / 2;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    void assign(int id, int l, int r, int ql, int qr, int val) {
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(id, l, r, val);
            return;
        }
        int mid = (l + r) / 2;
        push(id, l, r);
        assign(id << 1, l, mid, ql, qr, val);
        assign(id << 1 | 1, mid + 1, r, ql, qr, val);
        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    int query(int id, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (ql <= l && r <= qr) return ST[id].val;
        int mid = (l + r) / 2;
        push(id, l, r);
        return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
    }
};

vector<SegmentTree> ST(26, SegmentTree(MAXN));

void testcase() {
    int n, q; cin >> n >> q;
    cin >> s;
    s = " " + s;
    for (int i = 0; i < 26; i++) {
        ST[i].stat = char(i + 'a');
        ST[i].build(1, 1, n);
    }

    while (q--) {
        int l, r, k; cin >> l >> r >> k;

        vector<int> cnt(26, 0);

        for (int i = 0; i < 26; i++) {
            cnt[i] = ST[i].query(1, 1, n, l, r);
            ST[i].assign(1, 1, n, l, r, 0);
        }

        int cur = l;
        if (k) {
            for (int i = 0; i < 26; i++) {
                if (!cnt[i]) continue;
                ST[i].assign(1, 1, n, cur, cur + cnt[i] - 1, 1);
                cur += cnt[i];
            }
        } else {
            for (int i = 25; i >= 0; i--) {
                if (!cnt[i]) continue;
                ST[i].assign(1, 1, n, cur, cur + cnt[i] - 1, 1);
                cur += cnt[i];
            }
        }
    }

    vector<char> res(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int c = 0; c < 26; c++) {
            if (ST[c].query(1, 1, n, i, i)) {
                res[i] = char(c + 'a');
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << res[i];

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}