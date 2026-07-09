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
// Created: 2026-07-08 20:48

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "15"

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

const int MAXN = 1e5 + 5;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int sz) : n(sz), bit(sz + 1) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) bit[pos] += val;
    }

    int query(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & (-pos)) res += bit[pos];
        return res;
    }
};

struct Dat {
    int r, id;
};

Fenwick BIT(MAXN);
vector<Dat> g[MAXN]; // g[l] = r...


void testcase() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        g[l].pb({r, i});
    }

    vector<int> ans(n + 1, 0);

    for (int i = 1; i < MAXN; i++) {
        for (auto &[r, id] : g[i]) {
            BIT.update(r, 1);
        }
        for (auto &[r, id] : g[i]) {
            ans[id] = BIT.query(MAXN);
            if (r > 1) ans[id] -= BIT.query(r - 1);
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] - 1 << el;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}