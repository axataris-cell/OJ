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
// Created: 2026-07-16 15:11

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "1140F"

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

const int MAXN = 3e5 + 5;
const int MAXPOINTS = MAXN * 2 + 5;

int getid(bool axis, int num) {
    if (axis) return num;
    else return num + MAXN;
}

// rollback

vector<ll> ans(MAXN, 0);
ll cur = 0; // curans

struct Edge {
    int x, y; // x cords - y cords
};

struct Update {
    int u, sz;
    int cx, cy;
    ll oldres;
};

stack<Update> rollback;
vector<int> rollbackCnt(4 * MAXPOINTS, 0);
vector<vector<Edge>> ST(4 * MAXPOINTS);

vector<int> sz(MAXPOINTS, 1), par(MAXPOINTS, 0);
vector<int> cntx(MAXPOINTS, 0), cnty(MAXPOINTS, 0);

int find(int u) {
    return (u == par[u] ? u : find(par[u]));
}

void unite(int id, int x, int y) {
    x = find(getid(0, x));
    y = find(getid(1, y));
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    rollback.push({x, sz[x], cntx[x], cnty[x], cur});
    rollback.push({y, sz[y], cntx[y], cnty[y], cur});
    cur -= cntx[x] * cnty[x] + cntx[y] * cnty[y];
    rollbackCnt[id] += 2;

    par[y] = x;
    sz[x] += sz[y];
    cntx[x] += cntx[y];
    cnty[x] += cnty[y];
    cur += cntx[x] * cnty[x];
}

void update(int id, int l, int r, int ql, int qr, Edge e) {
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
        ST[id].push_back(e);
        return;
    }
    int mid = (l + r) / 2;
    update(id << 1, l, mid, ql, qr, e);
    update(id << 1 | 1, mid + 1, r, ql, qr, e);
}

void solve(int id, int l, int r) {
    // update the edges
    for (auto &[u, v] : ST[id]) {
        unite(id, u, v);
    }
    if (l == r) {
        ans[l] = cur;
    } else {
        int mid = (l + r) / 2;
        solve(id << 1, l, mid);
        solve(id << 1 | 1, mid + 1, r);
    }

    //rollback
    while (rollbackCnt[id]) {
        auto [u, oldsz, oldx, oldy, oldcur] = rollback.top();
        rollback.pop();
        par[u] = u;
        sz[u] = oldsz;
        cntx[u] = oldx;
        cnty[u] = oldy;
        cur = oldcur;
        --rollbackCnt[id];
    }
}

void testcase() {
    int n; cin >> n;
    for (int i = 0; i < MAXPOINTS; i++) {
        par[i] = i;
        if (i <= MAXN) {
            cntx[i] = 1;
        } else cnty[i] = 1;
    }

    map<pii, int> last;
    for (int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        auto &id = last[{x, y}];
        if (id == 0) {
            id = i;
        } else {
            update(1, 1, n, id, i - 1, {x, y});
            id = 0;
        }
    }

    for (auto &[e, id] : last) {
        if (id != 0) {
            auto &[x, y] = e;
            update(1, 1, n, id, n, {x, y});
        }
    }
    solve(1, 1, n);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
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