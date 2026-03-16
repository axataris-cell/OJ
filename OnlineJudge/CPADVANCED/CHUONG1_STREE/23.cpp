#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 18:14

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

vector<int> ST(4 * MAXN, 0);

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        ST[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);

    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return -LINF;
    if (ql <= l && r <= qr) {
        return ST[id];
    }

    int mid = (l + r) / 2;

    return max(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void testcase() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int mx = query(1, 1, n, i - k, i - 1);
        dp[i] = max(mx + a[i], a[i]);
        update(1, 1, n, i, dp[i]);
    }

    cout << max(query(1, 1, n, 1, n), 0LL);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}
