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

const int MAXN = 3e5 + 5;

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

vector<int> ans(MAXN, 0); // component count at 1..q

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
        ans[l] = compCnt;
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

    map<pii, int> last;
    queue<int> queries;

    for (int i = 1; i <= q; i++) {
        char t; cin >> t;
        if (t == '?') {
            queries.push(i);
            continue;
        }
        
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        if (t == '+') {
            last[{a, b}] = i;
        } else {
            update(1, 1, q, last[{a, b}], i, {a, b});
            last[{a, b}] = 0;
        }
    }

    for (auto &[e, idx] : last) {
        if (idx == 0) continue;
        auto &[u, v] = e;
        update(1, 1, q, idx, q, {u, v});
    }

    solve(1, 1, q);

    while (queries.size()) {
        int u = queries.front(); queries.pop();
        cout << ans[u] << el;
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