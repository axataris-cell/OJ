#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "CABLE"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=25,MOD=1e9+7,BASE=113,BLOCK=400;
struct DSU {
    vector<int> sz, par;
    DSU(int n) : sz(n + 1), par(n + 1) {}
    void init(int u) {
        sz[u] = 1;
        par[u] = u;
    }
    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }
    void unite(int u, int v) { // v->u
        u = find(u);
        v = find(v);
        if (u == v) return;
        sz[u] += sz[v];
        par[v] = u;
    }
};
vector<int> g[MAXN];
int h[MAXN];
vector<vector<int>> par(LOG, vector<int>(MAXN, 1));
void dfs(int u, int p) {
    for(int v : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[0][v] = u;
        dfs(v, u);
    }
}
int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    if (h[u] != h[v]) {
        int k = h[u] - h[v];
        for(int i = 0; i < LOG; i++) {
            if (k >> i & 1) {
                 u = par[i][u];
            }
        }
    }

    if (u==v) return u;

    for(int i = LOG - 1; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    return par[0][u];
}
void testcase() {
    int n, q; cin >> n >> q;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    DSU dsu(n + 1);
    for(int i = 1; i <= n; i++) dsu.init(i);
    auto apply =[&](int u, int v) -> void{
        int lc = lca(u, v);
        u = dsu.find(u);
        v = dsu.find(v);
        while (h[u] > h[lc]) {
            dsu.unite(par[0][u], u);
            u = dsu.find(u);
        }
        while (h[v] > h[lc]) {
            dsu.unite(par[0][v], v);
            v=  dsu.find(v);
        }
    };
    while (q--) {
        int t, u, v; cin >> t >>u >> v;
        if (t == 1) {
            apply(u, v);
        } else {
            u = dsu.find(u);
            v = dsu.find(v);
            cout << (u == v ? "YES" : "NO") << el;
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}