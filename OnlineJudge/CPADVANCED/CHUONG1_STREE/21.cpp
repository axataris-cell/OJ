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

#define int long long

const int MAXN = 1e5 + 5;

vector<int> ST(4 * MAXN, 0), lz(4 * MAXN, 0);

void push(int id, int l, int r) {
    if (lz[id] == 0) return;

    ST[id << 1] += lz[id];
    lz[id << 1] += lz[id];
    
    ST[id << 1 | 1] += lz[id];
    lz[id << 1 | 1] += lz[id];

    lz[id] = 0;
}

void update(int id, int l, int r, int x, int y, int val) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        ST[id] += val;
        lz[id] += val;
        return;
    }

    int mid = (l + r) / 2;
    push(id, l, r);

    update(id << 1, l, mid, x, y, val);
    update(id << 1 | 1, mid + 1, r, x, y, val);

    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int walk(int id, int l, int r, int x, int lo) {
    if (r < lo || ST[id] < x) return -1;
    if (l == r) return l;

    int mid = (l + r) / 2;
    push(id, l, r);

    int res = walk(id << 1, l, mid, x, lo);
    if (res != -1) return res;

    return walk(id << 1 | 1, mid + 1, r, x, lo);
}

void testcase() {
    int n; cin >> n;
    int q; cin >> q;

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, val; cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
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