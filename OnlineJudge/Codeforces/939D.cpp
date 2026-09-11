#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "939D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct DSU {
    vector<int> sz, par;
    DSU(int n) : sz(n + 1), par(n + 1) {}
    void init(int u) {
        sz[u] = 1;
        par[u ] = u;
    }
    int find(int u) {
        return (u == par[u] ? u : par[u] = find(par[u]));
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        par[v] = u;
        sz[u] += sz[v];
    }
};
void testcase() {
    int n;cin >> n;
    string s, t; cin >> s >> t;
    DSU dsu('z');
    for(int i = 'a'; i <= 'z'; i++) {
        dsu.init(i);
    }
    vector<pair<char,char>> res;
    for(int i = 0; i < n; i++) {
        int u = dsu.find(s[i]);
        int v = dsu.find(t[i]);
        if (u == v) continue;
        res.push_back({(char)u, (char)v});
        dsu.unite(u, v);
    }

    cout << res.size() << el;
    for(auto &[u, v] : res) {
        cout << u << ' ' << v << el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}