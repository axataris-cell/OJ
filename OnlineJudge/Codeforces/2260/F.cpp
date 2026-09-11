#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "F"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct DSU {
    vector<int> sz,par;
    DSU(int n) : sz(n + 1), par(n + 1) {}
    void init(int u) {
        sz[u] = 1;
        par[u] = u;
    }
    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
    }
};
void testcase() {
    int n, m; cin >> n >> m;
    struct Edge {int u, v;};
    vector<Edge> edges(m + 1);
    vector<vector<pii>> g(n + 1);

    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        edges[i] = {a, b};
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }

    bool ok = false;

    for (int i = 1; i <= m && !ok; i++) {
        DSU dsu(n);
        for (int k = 1; k <= n; k++) dsu.init(k);
        for (int j = 1; j <= m; j++) {
            if (j == i) continue;
            dsu.unite(edges[j].u, edges[j].v);
        }

        if (dsu.find(edges[i].u) != dsu.find(edges[i].v)) continue;

        int s = edges[i].u, t = edges[i].v;
        vector<int> node, curedge;
        vector<bool> vis(n + 1, false);

        auto dfs = [&](auto& self, int u) -> void {
            if (ok) return;
            node.push_back(u);
            vis[u] = true;
            if (u == t) {
                vector<bool> in(m + 1, false);
                in[i] = true;
                for (int id : curedge) in[id] = true;
                DSU dsu(n);
                for (int k = 1; k <= n; k++) dsu.init(k);
                for (int j = 1; j <= m; j++) {
                    if (!in[j]) {
                        dsu.unite(edges[j].u, edges[j].v);
                    }
                }
                int root = dsu.find(node[0]);
                bool valid = true;
                for (int v : node) {
                    if (dsu.find(v) != root) {
                        valid = false;
                        break;
                    }
                }
                if (valid) ok = true;
            } else {
                for (auto& [v, id] : g[u]) {
                    if (id == i || vis[v]) continue;
                    curedge.push_back(id);
                    self(self, v);
                    curedge.pop_back();
                    if (ok) return;
                }
            }
            vis[u] = false;
            node.pop_back();
        };

        dfs(dfs, s);
    }

    cout << (ok ? "YES" : "NO") << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}