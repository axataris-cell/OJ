#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "4"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<int> g[MAXN];
int sz[MAXN], heavy[MAXN], tin[MAXN], tout[MAXN], at[MAXN], h[MAXN];
int timeDfs=0;
void prep(int u, int p) {
    tin[u] = ++timeDfs;
    at[timeDfs] = u;
    sz[u] = 1;
    for(int v : g[u]) {
        if (v == p) continue;
        prep(v, u);
        h[v] = h[u] + 1;
        sz[u] += sz[v];
        if (sz[heavy[u]] < sz[v]) heavy[u] = v;
    }
    tout[u] = timeDfs;
}
int cnt[MAXN];
int res = 0;
void dfs(int u, int p, int keep) {
    for(int v : g[u]) if (v != p && v != heavy[u]) {
        dfs(v, u, false);
    }
    if (heavy[u]) dfs(heavy[u], u, true);

    

    if (!keep) {
        for(int i = tin[u]; i <= tout[u]; i++) {
            int v = at[i];
            --cnt[h[v]];
        }
    }
}
void testcase() {
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}