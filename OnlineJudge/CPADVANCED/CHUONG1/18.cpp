#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-15 19:51

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

vector<int> ST(4*MAXN, 0), lz(4*MAXN, 0);

void push(int id, int l, int r) {
    if (lz[id] == 0 || l == r) return;

    int mid = (l + r) / 2;
    ST[id << 1] = (mid - l + 1) - ST[id << 1];
    lz[id << 1] ^= 1;
    
    ST[id << 1 | 1] = (r - mid) - ST[id << 1 | 1];
    lz[id << 1 | 1] ^= 1;

    lz[id] = 0;
}

void update(int id, int l, int r, int x, int y) {
    if (l > y || r < x) return;
    if (x <= l && r <= y) {
        ST[id] = (r - l + 1) - ST[id];
        lz[id] ^= 1;
        return;
    }

    int mid = (l + r) / 2;
    push(id, l, r);

    update(id << 1, l, mid, x, y);
    update(id << 1 | 1, mid + 1, r, x, y);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int kth(int id, int l, int r, int k) {
    if (l == r) return l;

    push(id, l, r);
    int mid = (l + r) / 2;

    if (ST[id << 1] >= k) return kth(id << 1, l, mid, k);
    else return kth(id << 1 | 1, mid + 1, r, k - ST[id << 1]);
}

void testcase() {
    int n, q; cin >> n >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r;
            update(1, 1, n, l, r);
        } else {
            int k; cin >> k;
            if (ST[1] < k) cout << -1 << el;
            else cout << kth(1, 1, n, k) << el;
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