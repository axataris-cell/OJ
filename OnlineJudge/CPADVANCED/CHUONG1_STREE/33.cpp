#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define null nullptr
#define ll long long
#define ld long double
#define el '\n'

// Author: Axataris
// Created: 2026-03-17 15:32

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

const int MAXN = 2e5 + 5;

int n, q;

vector<int> a(MAXN, 0);
vector<int> ST(4 * MAXN, 0), ST2(4 * MAXN, 0); // ST: sum sq, ST2: sum
vector<int> lazy1(4 * MAXN, 0), lazy2(4 * MAXN, 0);
vector<bool> flag(4 * MAXN, 0); // có lazy set

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l] * a[l];
        ST2[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
    ST2[id] = ST2[id << 1] + ST2[id << 1 | 1];
}

void push1(int id, int l, int r) { // set
    if (!flag[id] || l == r) return;

    int val = lazy1[id];
    int mid = (l + r) / 2;

    int left = id << 1, right = id << 1 | 1;

    // left
    ST[left] = (mid - l + 1) * val * val;
    ST2[left] = (mid - l + 1) * val;
    lazy1[left] = val;
    lazy2[left] = 0;
    flag[left] = true;

    // right
    ST[right] = (r - mid) * val * val;
    ST2[right] = (r - mid) * val;
    lazy1[right] = val;
    lazy2[right] = 0;
    flag[right] = true;

    flag[id] = false;
    lazy1[id] = 0;
}

void push2(int id, int l, int r) { // add
    if (lazy2[id] == 0 || l == r) return;

    int val = lazy2[id];
    int mid = (l + r) / 2;

    int left = id << 1, right = id << 1 | 1;

    // LEFT
    ST[left] += 2 * val * ST2[left] + (mid - l + 1) * val * val;
    ST2[left] += (mid - l + 1) * val;

    if (flag[left]) lazy1[left] += val;
    else lazy2[left] += val;

    // RIGHT
    ST[right] += 2 * val * ST2[right] + (r - mid) * val * val;
    ST2[right] += (r - mid) * val;

    if (flag[right]) lazy1[right] += val;
    else lazy2[right] += val;

    lazy2[id] = 0;
}

void push(int id, int l, int r) {
    push1(id, l, r);
    push2(id, l, r);
}

void update1(int id, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id] = (r - l + 1) * val * val;
        ST2[id] = (r - l + 1) * val;
        lazy1[id] = val;
        lazy2[id] = 0;
        flag[id] = true;
        return;
    }
    push(id, l, r);

    int mid = (l + r) / 2;
    update1(id << 1, l, mid, ql, qr, val);
    update1(id << 1 | 1, mid + 1, r, ql, qr, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
    ST2[id] = ST2[id << 1] + ST2[id << 1 | 1];
}

void update2(int id, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id] += 2 * val * ST2[id] + (r - l + 1) * val * val;
        ST2[id] += (r - l + 1) * val;

        if (flag[id]) lazy1[id] += val;
        else lazy2[id] += val;

        return;
    }
    push(id, l, r);

    int mid = (l + r) / 2;
    update2(id << 1, l, mid, ql, qr, val);
    update2(id << 1 | 1, mid + 1, r, ql, qr, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
    ST2[id] = ST2[id << 1] + ST2[id << 1 | 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && r <= qr) return ST[id];

    push(id, l, r);

    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) +
           query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    while (q--) {
        int t; cin >> t;
        if (t == 0) {
            int l, r, val; cin >> l >> r >> val;
            update1(1, 1, n, l, r, val);
        } else if (t == 1) {
            int l, r, val; cin >> l >> r >> val;
            update2(1, 1, n, l, r, val);
        } else {
            int l, r; cin >> l >> r;
            cout << query(1, 1, n, l, r) << el;
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