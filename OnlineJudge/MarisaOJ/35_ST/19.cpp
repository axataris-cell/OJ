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
// Created: 2026-07-10 19:25

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "19"

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

int n, q;

vector<int> a(MAXN, 0);
vector<int> ST(4 * MAXN, 0); // min

struct Query {
    int l, id;
};
vector<Query> queries[MAXN];

void update(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id << 1, l, mid, pos, val);
    else update(id << 1 | 1, mid + 1, r, pos, val);
    ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return INF;
    if (ql <= l && r <= qr) return ST[id];
    int mid = (l + r) / 2;
    return min(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

int find(int id, int l, int r, int ql, int qr, int L) {
    if (r < ql || l > qr) return -1;

    if (ql <= l && r <= qr) {
        if (ST[id] >= L) return -1;
        if (l == r) return l;
    }

    int mid = (l + r) / 2;

    int res = find(id << 1, l, mid, ql, qr, L);
    if (res != -1) return res;

    return find(id << 1 | 1, mid + 1, r, ql, qr, L);
}


void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        queries[r].pb({l, i});
    }

    vector<int> ans(q + 1, 0);
    map<int, int> lastpos;
    for (int r = 1; r <= n; r++) {
        if (lastpos.count(a[r])) {
            update(1, 1, n, r, lastpos[a[r]]);
            update(1, 1, n, lastpos[a[r]], INF);
        }
        else {
            update(1, 1, n, r, 0);
        }
        for (auto &[l, id] : queries[r]) {
            int pos = find(1, 1, n, l, r, l);

            if (pos == -1) ans[id] = 0;
            else ans[id] = a[pos];
        }
        lastpos[a[r]] = r;
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}