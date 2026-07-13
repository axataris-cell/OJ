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
// Created: 2026-07-11 14:24

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "20"

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

const int MAXN = 1e6 + 5;

struct SegmentTree {
    vector<int> ST;
    int n;

    SegmentTree(int sz) : n(sz), ST(4 * sz + 1) {}

    void build(int id, int l, int r) {
        if (l == r) {
            ST[id] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r) {
            ST[id] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        
        ST[id] = ST[id << 1] + ST[id << 1 | 1];
    }

    int walk(int id, int l, int r, int k) {
        if (l == r) return l;

        int mid = (l + r) / 2;

        if (ST[id << 1] > k) return walk(id << 1, l, mid, k);
        else return walk(id << 1 | 1, mid + 1, r, k - ST[id << 1]);
    }
};

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    SegmentTree ST(n);
    ST.build(1, 1, n);

    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int pos = ST.walk(1, 1, n, a[i]);
        res[pos] = i;
        ST.update(1, 1, n, pos, -1);
    }

    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}