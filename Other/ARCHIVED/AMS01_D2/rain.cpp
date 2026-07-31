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
// Created: 2026-07-07 08:34

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "rain"

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
    if (FILE *f = fopen(FILENAME".inp", "r")) {
        fclose(f);
        freopen(FILENAME".inp", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

#define int long long

struct Fenwick {
    vector<int> bit;
    int n;

    Fenwick(int sz) : bit(sz + 1), n(sz) {}

    void update(int pos, int val) {
        for (; pos <= n; pos += pos & (-pos)) {
            bit[pos] += val;
        }
    }

    int query(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & (-pos)) res += bit[pos];
        return res;
    }
};

struct Query {
    int l, r, h, id;
};

void testcase() {
    // cout << ((3 + 4 + 2 + 1 + 3) ^ (5 + 2 + 6 + 4 + 3 + 5) ^ (7 + 4 + 8 + 6 + 5 + 7 + 1));
    // return;

    int n, q, t; cin >> n >> q >> t;
    vector<pii> tower(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> tower[i].fi;
        tower[i].se = i;
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].l >> queries[i].r >> queries[i].h;
        queries[i].id = i;
    }
    if (tower[1].fi == tower[n].fi && tower[n].fi == 1e9) { // sub 3
        vector<int> ans(q, 0);
        sort(tower.begin() + 1, tower.end());
        sort(all(queries), [](Query a, Query b) {
            return a.h < b.h;
        });
        Fenwick BIT(n);
        Fenwick cnt(n); // count
        int cur = 1;
        for (auto &[l, r, h, id] : queries) {
            while (cur <= n && tower[cur].fi < h) {
                BIT.update(tower[cur].se, tower[cur].fi);
                cnt.update(tower[cur].se, 1);
                ++cur;
            }
            ans[id] += h * cnt.query(n) - BIT.query(n);
        }
        int res = 0;
        for (int i = 0; i < q; i++) {
            res ^= ans[i];
        }

        cout << res;
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