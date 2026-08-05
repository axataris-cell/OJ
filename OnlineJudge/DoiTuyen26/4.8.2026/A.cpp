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
// Created: 2026-08-04 19:15

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "A"

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
    vector<int> sz, par, col;

    DSU(int n) : sz(n + 1), par(n + 1), col(n + 1) {}

    void init(int u) {
        sz[u] = 1;
        par[u] = u;
        col[u] = 0;
    }

    int find(int x) {
        if (par[x] == x) return x;
        int p = find(par[x]);
        col[x] ^= col[par[x]];
        return par[x] = p;
    }

    bool unite(int a, int b, int w) { //w = 0 là cùng nhóm, w = 1 là khác nhóm
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return (col[a] ^ col[b]) == w;

        par[pa] = pb;
        col[pa] = col[a] ^ col[b] ^ w;
        return true;
    }
};

void testcase() {
    int n, m; cin >> n >> m;

    DSU dsu(m);
    for (int i = 1; i <= m; i++) {
        dsu.init(i);
    }

    bool bruh = false;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int a, b; cin >> a >> b;
        if (!dsu.unite(a, b, x)) {
            bruh = true;
        }
    }

    if (bruh) {
        cout << -1;
        return;
    }

    for (int i = 1; i <= m; i++) {
        int j = dsu.find(i); // bruh
    }

    vector<int> res;
    for (int i = 1; i <= m; i++) {
        if (dsu.col[i]) res.pb(i);
    }

    if (res.size() == 0) {
        cout << m << el;
        for (int i = 1; i <= m; i++) {
            cout << i << ' ';
        }
        return;
    }

    cout << res.size() << el;
    for (auto x : res) cout << x << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}