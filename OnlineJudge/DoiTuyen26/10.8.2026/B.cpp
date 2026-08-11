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
// Created: 2026-08-10 08:36

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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> adj[MAXN]; // for centroid decomp
char res[MAXN];

int sz[MAXN];
bool del[MAXN];

void dfsChild(int u, int p) {
    sz[u] = 1;
    for (int v : g[u]) if (v != p && !del[v]) {
        dfsChild(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p, int n) {
    for (int v : g[u]) if (v != p && !del[v] && sz[v] > n / 2) return centroid(v, u, n);
    return u;
}

int h[MAXN];
bool ans = true;

void solve(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        if (h[v] >= 26) {
            ans = false;
            return;
        }
        res[v] = res[u] + 1;
        solve(v, u);
    }
}

void testcase() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfsChild(1, 1);
    int root = centroid(1, 1, n);
    del[root] = true;
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (del[v]) continue;
            dfsChild(v, v);
            int c = centroid(v, v, sz[v]);
            del[c] = true;
            adj[u].pb(c);
        }
        for (int v : adj[u]) {
            q.push(v);
        }
    }
    res[root] = 'A';
    solve(root, root);
    if (!ans) {
        cout << "Impossible!";
        return;
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    file();

    int t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}