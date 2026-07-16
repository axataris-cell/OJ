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
// Created: 2026-07-15 16:18

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "IterativeSegtree"

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

vector<int> a(MAXN, 0);
vector<int> ST(2 * MAXN, 0);

int n;

void build() {
    for (int i = 1; i <= n; i++) ST[n + i - 1] = a[i];
    for (int i = n - 1; i > 0; i--) ST[i] = max(ST[i << 1], ST[i << 1 | 1]);
}

void update(int p, int val) {
    for (ST[p += n - 1] += val; p > 1; p >>= 1) {
        ST[p >> 1] = max(ST[p], ST[p ^ 1]);
    }
}

int query(int l, int r) {
    int res = -INF;
    for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, ST[l++]);
        if (r & 1) res = max(res, ST[--r]);
    }
    return res;
}

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build();
    int q; cin >> q;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}