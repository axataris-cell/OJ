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
// Created: 2026-08-05 09:57

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "D"

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

int ST[8 * MAXN], lz[8 * MAXN];
int a[2][MAXN];

void push(int id, int l, int r) {
    if (!lz[id]) return;

    int mid = (l + r) / 2;

    ST[id << 1] = (mid - l + 1) - ST[id << 1];
    lz[id << 1] ^= 1;

    ST[id << 1 | 1] = (r - mid) - ST[id << 1 | 1];
    lz[id << 1 | 1] ^= 1;

    lz[id] = 0;
    return;
}

void update(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id] = (r - l + 1) - ST[id];
        lz[id] ^= 1;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    update(id << 1, l, mid, ql, qr);
    update(id << 1 | 1, mid + 1, r, ql, qr);
    ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int pos) {
    if (l == r) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    if (pos <= mid) return query(id << 1, l, mid, pos);
    else return query(id << 1 | 1, mid + 1, r, pos);
}

void testcase() {
    int n, q; cin >> n >> q;
    vector<int> comp;
    comp.reserve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[0][i] >> a[1][i];
        comp.pb(a[0][i]);
        comp.pb(a[1][i]);
    }

    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    int m = comp.size();

    while (q--) {
        int C; cin >> C;
        int bruh = upper_bound(all(comp), C) - comp.begin() - 1; // 1 idx
        if (bruh < 0) continue;
        bruh++;
        bruh = min(bruh, n);
        update(1, 1, m, 1, bruh);
    }
    for (int i = 1; i <= n; i++) {
        int bruh = lower_bound(all(comp), a[0][i]) - comp.begin() + 1;
        int state = query(1, 1, m, bruh);
        cout << a[state][i] << ' ';
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