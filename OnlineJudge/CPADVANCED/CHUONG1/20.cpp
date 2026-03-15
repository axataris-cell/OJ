#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-15 20:15

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1e5 + 5;

vector<int> a(MAXN, 0);
vector<int> ST(4 * MAXN, 0);

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(id << 1, l, mid, pos, val);
    } else {
        update(id << 1 | 1, mid + 1, r, pos, val);
    }

    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int walk(int id, int l, int r, int x, int lo) {
    if (r < lo || ST[id] < x) return -1;

    if (l == r) return l;

    int mid = (l + r) / 2;

    int res = walk(id << 1, l, mid, x, lo);
    if (res != -1) return res;

    return walk(id << 1 | 1, mid + 1, r, x, lo);
}

void testcase() {
    int n; cin >> n;
    int q; cin >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int i, val; cin >> i >> val;
            update(1, 1, n, i, val);
        } else {
            int x; cin >> x;
            int l; cin >> l;
            if (ST[1] < x) cout << -1 << el;
            else cout << walk(1, 1, n, x, l) << el;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}