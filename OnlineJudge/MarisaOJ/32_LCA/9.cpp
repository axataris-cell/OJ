#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME ""

using namespace std;

using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
    if (FILE *f = fopen(FILENAME".INP", "r")) {
        fclose(f);
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
}

const int MAXN = 1e5 + 5;
const int LOG = 19;

int n, q;
vector<int> g[MAXN], h(MAXN, 0), low(MAXN);
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
bool vis[MAXN];

void dfs(int u) {
	low[u] = u;
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            h[v] = h[u] + 1;
            par[0][v] = u;
            dfs(v);
            
            if (h[low[v]] > h[low[u]]) low[u] = low[v];
        }
    }
}

void preprocess() {
    dfs(1);
    for (int i = 1; i <= LOG; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for (int i = 0; i <= LOG; i++) {
            if (k >> i & 1) u = par[i][u];
        }
    }
    if (u == v) return u;
    for (int i = LOG; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}

int ancestor_k(int u, int k) {
    for (int i = 0; i <= LOG; i++) {
        if (k >> i & 1) {
            u = par[i][u];
        }
    }
    return u;
}

int dist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

int res(int u, int v) {
    int anc = lca(u, v);
    int d = dist(u, v);
    if (h[u] <= h[v]) {
        int x = ancestor_k(v, (d + 1) / 2 - 1);
        return dist(u, x) + h[low[x]] - h[x]; //ok 
    } else {
    	int x = ancestor_k(u, (d + 1) / 2);
    	return max({dist(u, x) + h[low[x]] - h[x], dist(u, 1)}); //?
    }
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    preprocess();
//    for (int i = 1; i <= n; i++) cout << low[i] << ' ';
//    cout << el;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << res(u, v) << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    file();

    ll t = 1; //cin >> t;
    while (t--) testcase();

    return 0;
}
