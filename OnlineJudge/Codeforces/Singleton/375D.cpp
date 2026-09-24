#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "375D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<int>g[MAXN];
struct Query
{
    int idx, k;
};
vector<Query>queries[MAXN];
int ans[MAXN];
int color[MAXN];
int at[MAXN], tin[MAXN], tout[MAXN];
int sz[MAXN], heavy[MAXN];
int timeDfs=0;
void etour(int u, int p) {
    tin[u] = ++timeDfs;
    at[timeDfs] = u;
    sz[u] = 1;
    for(int v : g[u]) {
        if (v == p) continue;
        etour(v, u);
        sz[u] += sz[v];
        if (sz[heavy[u]] < sz[v]) {
            heavy[u] = v;
        }
    }
    tout[u] = timeDfs;
}
int f[MAXN];
int mp[MAXN];
void dfs(int u, int p, bool keep) {
    for(int v : g[u]) if (v != heavy[u] && v != p) {
        dfs(v, u, false);
    }
    if (heavy[u]) dfs(heavy[u], u, true);
    ++mp[color[u]];
    ++f[mp[color[u]]];
    for(int v : g[u]) if (v != heavy[u] && v != p) {
        for(int i = tin[v]; i <= tout[v]; i++) {
            int node = at[i];
            ++mp[color[node]];
            ++f[mp[color[node]]];
        }
    }
    for (auto &[id, k] : queries[u]) {
        ans[id] = f[k];
    }
    if (!keep) {
        for (int i = tin[u]; i <= tout[u]; i++) {
            int v = at[i];
            --f[mp[color[v]]];
            --mp[color[v]];
        }
    }
}
void testcase() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    etour(1, 1);
    for(int i = 1; i <= q; i++) {
        int u, k; cin >> u >> k;
        queries[u].push_back({i, k});
    }
    dfs(1, 1, 1);
    for(int i = 1; i <= q; i++) {
        cout << ans[i] << el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}