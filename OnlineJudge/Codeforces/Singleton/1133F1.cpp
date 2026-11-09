#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

vector<int> g[MAXN];

struct DSU {
    vector<int> sz, par;

    DSU(int n) : sz(n + 1), par(n + 1) {}

    void init(int u) {
        par[u] = u;
        sz[u] = 1;
    }

    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

struct Edge {
    int u, v;
};
vector<Edge> res;
vector<Edge> edges;

void testcase() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back({a, b});
    }

    int mxdeg = 0;
    int node = -1;

    for (int i = 1; i <= n; i++) {
        if (g[i].size() > mxdeg) {
            mxdeg = g[i].size();
            node = i;
        }
    }

    DSU dsu(n);
    for (int i = 1; i <= n; i++) dsu.init(i);

    for (auto u : g[node]) {
        dsu.unite(node, u);
        res.push_back({node, u});
    }

    for (auto &[u, v] : edges) {
        if (dsu.unite(u, v)) {
            res.push_back({u, v});
        }
    }

    for (auto &[u, v] : res) {
        cout << u << ' ' << v << el;
    }


}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}