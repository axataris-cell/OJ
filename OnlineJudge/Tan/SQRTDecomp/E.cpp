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
// Created: 2026-07-22 17:49

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "E"

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

const int MAXN = 3e5 + 5;
const int BLOCK = 400;
int n, q;
int SZ = 0;
vector<int> ST(2 * 524288, 0);
void update(int pos, int val) {
    int SZ = 524288;
    for (ST[pos += SZ]+=val; pos > 0; pos >>= 1) {
        ST[pos >> 1] = max(ST[pos], ST[pos ^ 1]);
    }
}
int walk(int k) {
    int SZ = 524288;
    if (ST[1] <= k) return -1;
    int p = 1;
    while (p < SZ) {
        if (ST[p << 1] > k)
            p <<= 1;
        else {
            p = p << 1 | 1;
        }
    }
    return p - SZ;
}
struct Query {int l, r, k, id;};
void testcase() {
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<Query> queries; vector<int> ans(q + 1, 0);
    for (int i = 1; i <= q; i++) {
        int l, r, k; cin >> l >> r >> k;
        queries.pb({l, r, k, i});
    }
    sort(all(queries), [](const Query &x, const Query &y) {
        if (x.l / BLOCK != y.l / BLOCK) return x.l / BLOCK < y.l / BLOCK;
        if ((x.l / BLOCK) & 1) return x.r < y.r;
        else return x.r > y.r;
    });
    int L = 1;
    int R = 0;
    auto add = [&](int &pos) {
        update(a[pos], 1);
    };
    auto remove = [&](int &pos) {
        update(a[pos], -1);
    };
    for (auto &[l, r, k, id] : queries) {
        while (L > l) {
            --L;
            add(L);
        }
        while (L < l) {
            remove(L);
            ++L;
        }
        while (R > r) {
            remove(R);
            --R;
        }
        while (R < r) {
            ++R;
            add(R);
        }
        ans[id] = walk((r - l + 1) / k);
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