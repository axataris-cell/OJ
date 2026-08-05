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
// Created: 2026-08-03 15:29

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "CHIADOAN"

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

#define int long long

/*
5
5 3 2 2 5
2
9
8
*/

const int MAXN = 1e5 + 5;

int n;

vector<int> a(MAXN, 0);
vector<int> f(MAXN, 0);

vector<int> ST(4 * MAXN, 0);
vector<int> lz(4 * MAXN, 0);

void push(int id, int l, int r) {
    if (!lz[id]) return;

    int mid = (l + r) / 2;

    ST[id << 1] += lz[id];
    lz[id << 1] += lz[id];

    ST[id << 1 | 1] += lz[id];
    lz[id << 1 | 1] += lz[id];

    lz[id] = 0;
    return;
}

void updatePoint(int id, int l, int r, int pos, int val) {
    if (l == r) {
        ST[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    if (pos <= mid) updatePoint(id << 1, l, mid, pos, val);
    else updatePoint(id << 1 | 1, mid + 1, r, pos, val);
    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

void updateRange(int id, int l, int r, int ql, int qr, int val) {
    if (l > qr || r < ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        ST[id] += val;
        lz[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    updateRange(id << 1, l, mid, ql, qr, val);
    updateRange(id << 1 | 1, mid + 1, r, ql, qr, val);

    ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return -LINF;
    if (ql <= l && r <= qr) {
        return ST[id];
    }
    int mid = (l + r) / 2;
    push(id, l, r);
    return max(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
}

void solve(int C) {
    vector<int> K(n + 1, 0);
    vector<int> S(n + 1, 0);

    vector<int> st; // mn stack

    for (int i = 1; i <= n; i++) {
        updatePoint(1, 0, n, i - 1, S[i - 1] + a[i]);

        while (!st.empty() && a[st.back()] <= a[i]) {
            int last = st.back();
            st.pop_back();
            int l = st.empty() ? 0 : st.back();
            int r = last - 1;
            updateRange(1, 0, n, l, r, a[i] - a[last]);
        }
        st.pb(i);

        int L = lower_bound(f.begin(), f.begin() + i, f[i] - C) - f.begin();
        int R = upper_bound(K.begin() + L, K.begin() + i, K[L]) - K.begin() - 1;

        int mx = query(1, 0, n, L, R);

        K[i] = K[L] + 1;
        S[i] = mx;
    }

    cout << K[n] << ' ' << S[n] << el;
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    int q; cin >> q;
    while (q--) {
        int C; cin >> C;
        for (int i = 0; i < 4 * MAXN; i++) {
            ST[i] = 0;
            lz[i] = 0;
        }
        solve(C);
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