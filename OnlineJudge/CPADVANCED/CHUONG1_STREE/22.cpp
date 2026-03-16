#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-16 07:07

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

const int MAXN = 2e5 + 5;

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

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void update(int id, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int walk(int id, int l, int r, int k) {
    if (l == r) return l;

    int mid = (l + r) / 2;

    if (ST[id << 1] <= k) return 0;
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        int res = walk(1, 1, n, a[k]);
        cout << a[res] << ' ';
        update(1, 1, n, res, 0);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}