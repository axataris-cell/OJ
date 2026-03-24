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
// Created: 2026-03-24 16:14

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "136"

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

vector<int> g[MAXN];
map<pii, int> color;

void dfs(int u, int p, int co) {
    int x = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        ++x;
        if (x == co) ++x;

        color[{u, v}] = x;
        dfs(v, u, x);
    }
}

struct edge {
    int u, v;
};

void testcase() {
    int n; cin >> n;
    vector<edge> edges;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        edges.pb({a, b});
    }
    int best = 0;
    int node = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > best) {
            best = g[i].size();
            node = i;
        }
    }
    dfs(node, node, 0);

    cout << best << el;
    for (auto e : edges) {
        cout << (color[{e.u, e.v}] ? color[{e.u, e.v}] : color[{e.v, e.u}]) << el;
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