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
// Created: 2026-04-13 19:30

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "DODADANG"

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

const int MAXN = 1e4 + 5;

int ST[4 * MAXN];
int lz[4 * MAXN];
int dp[MAXN];
int ndp[MAXN];
int last[MAXN];
int a[MAXN];

void build(int node, int l, int r) {
    lz[node] = 0;
    if (l == r) {
        ST[node] = dp[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(node << 1, l, mid);
    build((node << 1) | 1, mid + 1, r);
    ST[node] = max(ST[node << 1], ST[(node << 1) | 1]);
}

inline void push(int node) {
    if (lz[node] != 0) {
        int left = node << 1;
        int right = left | 1;
        int val = lz[node];
        
        ST[left] += val;
        lz[left] += val;
        ST[right] += val;
        lz[right] += val;
        
        lz[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        ST[node] += val;
        lz[node] += val;
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, ql, qr, val);
    update((node << 1) | 1, mid + 1, r, ql, qr, val);
    ST[node] = max(ST[node << 1], ST[(node << 1) | 1]);
}

int query(int node, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return -INF;
    if (ql <= l && r <= qr) return ST[node];
    push(node);
    int mid = (l + r) >> 1;
    return max(query(node << 1, l, mid, ql, qr), query((node << 1) | 1, mid + 1, r, ql, qr));
}

void testcase() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; ++i) {
        dp[i] = -INF;
    }
    dp[0] = 0;

    for (int k = 1; k <= q; ++k) {
        build(1, 0, n);

        for (int i = 0; i < MAXN; ++i) {
            last[i] = 0;
        }

        for (int i = 0; i <= n; ++i) {
            ndp[i] = -INF;
        }

        for (int i = 1; i <= n; ++i) {
            int x = a[i];

            update(1, 0, n, last[x], i - 1, 1);
            last[x] = i;

            if (i >= k) {
                ndp[i] = query(1, 0, n, k - 1, i - 1);
            }
        }

        cout << ndp[n] << ' ';

        for (int i = 0; i <= n; ++i) {
            dp[i] = ndp[i];
        }
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