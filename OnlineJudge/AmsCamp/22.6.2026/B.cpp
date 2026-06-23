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
// Created: 2026-06-22 15:03

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "B"

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

struct DSU {
    vector<int> sz, par, mn;

    DSU(int n) : sz(n), par(n), mn(n) {}

    void make(int i) {
        sz[i] = 1;
        par[i] = i;
        mn[i] = i;
    }

    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    void join(int u, int v) { // u = par v
        u = find(u);
        v = find(v);
        if (u == v) return;
        par[v] = u;
        sz[u] += sz[v];
        mn[u] = min(mn[u], mn[v]);
    }
};

struct Query {
    int id, day, ans;
};

void testcase() {
    int n, d; cin >> n >> d;

    vector<int> a(n, 0);
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    sort(rall(b));

    vector<Query> q(d);
    for (int i = 0; i < d; i++) {
        cin >> q[i].day;
        q[i].id = i;
        q[i].ans = 0;
    }

    sort(all(q), [](Query x, Query y) {
        return x.day > y.day;
    });

    DSU dsu(n);
    for (int i = 0; i < n; i++) dsu.make(i);

    vector<bool> active(n, false);
    int icnt = 0;
    int b_idx = 0;

    for (auto &query : q) {
        int x = query.day;
        
        while (b_idx < n && b[b_idx].first > x) {
            int idx = b[b_idx].second;
            active[idx] = true;
            icnt++;


            if (idx > 0 && active[idx - 1]) {
                if (dsu.find(idx) != dsu.find(idx - 1)) {
                    dsu.join(idx, idx - 1);
                    icnt--;
                }
            }

            if (idx < n - 1 && active[idx + 1]) {
                if (dsu.find(idx) != dsu.find(idx + 1)) {
                    dsu.join(idx, idx + 1);
                    icnt--;
                }
            }
            b_idx++;
        }
        query.ans = icnt;
    }

    sort(all(q), [](Query x, Query y) {
        return x.id < y.id;
    });

    for (int i = 0; i < d; i++) {
        cout << q[i].ans << (i == d - 1 ? "" : " ");
    }
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; cin >> t;
    while (t--) testcase();

    return 0;
}