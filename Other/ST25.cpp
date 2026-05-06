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
// Created: 2026-05-05 08:12

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "ST25"

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

const int MAXN = 2e5 + 5;

vector<int> ST(4 * MAXN, 0);
vector<int> a(MAXN, 0);

// ST -> tong, min, max, gcd, xor, maxprefix sum, ngoac dung
// update:
// cong them
// thay the
// thay nhung phan tu > x -> x segment tree beats
// cap nhat doan (cong, tru doan / thay the doan) (lazy propragation) / diem
// luu lai cac lan update (persistent segment tree)
// segmentree rollback ?`

void build(int id, int l, int r) {
    if (l == r) {
        ST[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id << 1, l, mid); // id * 2
    build(id << 1 | 1, mid + 1, r); // id * 2 + 1
    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    // cap nhat mot diem -> cap nhat khong qua log2(n) node.
    if (pos <= mid) update(id << 1, l, mid, pos, val);
    else update(id << 1 | 1, mid + 1, r, pos, val);

    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return ST[id];
    int mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) + query(id << 1 | 1, mid + 1, r, ql, qr);
}

void testcase() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}