#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "722C"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct DSU {
    vector<int> sz,par,sum;
    DSU(int n) : sz(n + 1), par(n + 1), sum(n + 1, 0) {}
    void init(int u, int val) {
        sz[u] = 1;
        par[u ] = u;
        sum[u] = val;
    }
    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }
    void unite(int u, int v ){
        u = find(u);
        v = find(v);
        if (u == v) return;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u ;
        sz[u] += sz[v];
        sum[u] += sum[v];
    }
};
void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1), p(n + 1, 0);
    vector<bool> activated(n + 1, false);
    DSU dsu(n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dsu.init(i, a[i]);
    }
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int res = 0;
    vector<int> ans;
    for(int i = n; i > 1; i--) {
        activated[p[i]] = true;
        if (p[i] != 1 && activated[p[i] - 1]) {
            dsu.unite(p[i], p[i] - 1);
        }
        if (p[i] != n && activated[p[i] + 1]) {
            dsu.unite(p[i], p[i] + 1);
        }
        int cur = dsu.find(p[i]);
        res = max(res, dsu.sum[cur]);
        ans.push_back(res);
    }
    reverse(ans.begin(),ans.end());
    for(auto x : ans) cout << x << el;
    cout << 0 << el;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}