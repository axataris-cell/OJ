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

#define FILENAME "21"

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

// XOR

const int LOG = 30;
const int MAXN = 1e5 + 5;

vector<int> a(MAXN, 0);

struct SegmentTree {

    struct Node {
        int cnt0;
        int cnt1;
        Node() : cnt0(0), cnt1(0) {}
    };

    vector<Node> ST;
    int n;
    int level; // bit level (goes to LOG)

    SegmentTree(int sz) : n(sz), ST(4 * sz + 1, Node()) {}

    void build(int id, int l, int r) {
        if (l == r) {
            if (a[l] >> level & 1) ++ST[id].cnt1;
            else ++ST[id].cnt0;
            return;
        }
        int mid = (l + r) / 2;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        ST[id].cnt0 = ST[id << 1].cnt0 + ST[id << 1 | 1].cnt0;
        ST[id].cnt1 = ST[id << 1].cnt1 + ST[id << 1 | 1].cnt1;
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            ST[id].cnt0 = ST[id].cnt1 = 0;
            if (val >> level & 1) ++ST[id].cnt1;
            else ++ST[id].cnt0;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        ST[id].cnt0 = ST[id << 1].cnt0 + ST[id << 1 | 1].cnt0;
        ST[id].cnt1 = ST[id << 1].cnt1 + ST[id << 1 | 1].cnt1;
    }

    int query(int id, int l, int r, int ql, int qr, int type) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) {
            if (type & 1) return ST[id].cnt1;
            else return ST[id].cnt0;
        }
        int mid = (l + r) / 2;
        return query(id << 1, l, mid, ql, qr, type) + query(id << 1 | 1, mid + 1, r, ql, qr, type);
    }
};

vector<SegmentTree> ST(LOG, SegmentTree(MAXN));

void testcase() {
    int n; cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < LOG; i++) {
        ST[i].level = i;
        ST[i].build(1, 0, n); // also count pref 0 == 0
    }
    while (q--) {
        int t, x, y; cin >> t >> x >> y;
        if (t == 1) {
            for (int i = 0; i < LOG; i++) ST[i].update(1, 0, n, x, y);
        } else {
            ll res = 0;
            for (int i = 0; i < LOG; i++) {
                ll cnt0 = ST[i].query(1, 0, n, x - 1, y, 0);
                ll cnt1 = ST[i].query(1, 0, n, x - 1, y, 1);
                res += (1LL << i) * cnt0 * cnt1;
            }
            cout << res << el;
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