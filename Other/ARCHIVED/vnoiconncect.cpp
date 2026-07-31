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
// Created: 2026-07-16 11:56

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "connect"

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
    if (FILE *f = fopen(FILENAME".in", "r")) {
        fclose(f);
        freopen(FILENAME".in", "r", stdin);
        freopen(FILENAME".out", "w", stdout);
    }
}

const int MAXN = 1e5 + 5;

vector<int> par(MAXN), sz(MAXN, 1);

struct Edge {
    int u, v;
};

struct Update {
    int root, sz;
};

stack<Update> rollback;
vector<vector<Edge>> ST(4 * MAXN);
vector<int> rollbackCnt(4 * MAXN, 0);

struct Query {
    int x, y, id;
};

vector<Query> queries[MAXN];
bool ans[MAXN];

int find(int u) { // no path comppression
    return (u == par[u] ? u : find(par[u]));
}

void unite(int id, int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    // ... save update
    rollback.push({u, sz[u]});
    rollback.push({v, sz[v]});
    rollbackCnt[id] += 2;
    sz[u] += sz[v];
    par[v] = u;
    return;
}

int compCnt = 0;

void update(int id, int l, int r, int ql, int qr, Edge e) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id].pb(e);
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, ql, qr, e);
    update(id << 1 | 1, mid + 1, r, ql, qr, e);
}

void solve(int id, int l, int r) {
    for (auto &e : ST[id]) {
        unite(id, e.u, e.v);
    }
    compCnt -= rollbackCnt[id] >> 1;
    if (l == r) {
        for (auto [x, y, idx] : queries[l]) {
            x = find(x);
            y = find(y);
            if (x == y) ans[idx] = true;
        }
    } else {    
        int mid = (l + r) / 2;
        solve(id << 1, l, mid);
        solve(id << 1 | 1, mid + 1, r);
    }

    // rollback
    compCnt += rollbackCnt[id] >> 1;

    while (rollbackCnt[id]) {
        auto [u, osz] = rollback.top();
        rollback.pop();
        par[u] = u;
        sz[u] = osz;
        --rollbackCnt[id];
    }
}

void testcase() {
    int n, q; cin >> n >> q;
    compCnt = n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }

    map<pii, pii> last; // idx - cnt
    queue<int> qq;

    for (int i = 1; i <= q; i++) {
        int t; cin >> t;
        if (t == 3) {
            int x, y; cin >> x >> y;
            queries[i].push_back({x, y, i});
            qq.push(i);
            continue;
        }
        
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);

        auto &[idx, cnt] = last[{a, b}];

        if (t == 1) {
            if (cnt == 0) {
                idx = i;
            }
            cnt++;
        } else {
            if (cnt == 0) continue;
            --cnt;
            if (cnt == 0) {
                update(1, 1, q, idx, i, {a, b});
                idx = 0;
            }
        }
    }

    for (auto &[e, k] : last) {
        if (k.fi == 0) continue;
        auto &[u, v] = e;
        update(1, 1, q, k.fi, q, {u, v});
    }

    solve(1, 1, q);

    while (qq.size()) {
        int u = qq.front(); qq.pop();
        cout << ans[u];
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