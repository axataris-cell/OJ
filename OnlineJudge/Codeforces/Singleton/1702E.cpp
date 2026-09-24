#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1702E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
struct DSU {
    vector<int> sz,par,col;
    DSU(int n) : sz(n + 1), par(n + 1), col(n + 1) {}
    void init(int u) {
        sz[u] = 1;
        par[u] = u;
        col[u] = 0;
    }

    int find(int x) {
        if (par[x] == x) return x;
        int p = find(par[x]);
        col[x] ^= col[par[x]];
        return par[x] = p;
    }

    bool unite(int a, int b, int w) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return (col[a] ^ col[b]) == w;

        par[pa] = pb;
        col[pa] = col[a] ^ col[b] ^ w;
        return true;
    }

};
void testcase() {
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(i);
        g[y].push_back(i);
    }
    DSU dsu(n);
    for(int i =1; i <= n; i++) dsu.init(i);

    for(int i = 1; i <= n; i++) {
        if (g[i].size() > 2) {
            cout << "NO" << el;
            return;
        }
        if (g[i].size() == 2) {
            if (!dsu.unite(g[i][0], g[i][1], 1)) {
                cout << "NO" << el;
                return;
            }
        }
    }

    cout << "YES" << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}