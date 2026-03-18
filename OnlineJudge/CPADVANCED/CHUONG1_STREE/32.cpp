#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 21:37

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

vector<int> ST(4 * MAXN, 0), lz(4 * MAXN, 0);

void build(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) {
        build(id << 1, l, mid, pos, val);
    } else build(id << 1 | 1, mid + 1, r, pos, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();

    for (int i = 1; i <= n; i++) build(1, 1, n, a[i], 1);
    int m = b.size() - 1;

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        auto it = lower_bound(b.begin() + 1, b.begin() + n + 1, t) - b.begin();
        cout << query(1, 1, n, it, m) << el;
        
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}