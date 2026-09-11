#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int color[MAXN];
int ans[MAXN];
vector<int> g[MAXN];
map<int, int> mp[MAXN];
void dfs(int u, int p) {
    for(int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (mp[u].size() < mp[v].size()) swap(mp[u], mp[v]);
        for(auto &[k, v] : mp[v]) {
            mp[u][k] += v;
        }
    }
    ++mp[u][color[u]];
    ans[u] = mp[u].size();
}
void testcase() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}