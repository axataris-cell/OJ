#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "Asya"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
vector<int> st[MAXN];
struct DSU{
    vector<int>sz,par;
    DSU(int n):sz(n),par(n){}
    void init(int u){sz[u]=1,par[u]=u;}
    int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        if(sz[u]<sz[v])swap(u,v);
        for(auto k:st[v]){
            st[u].push_back(k);
        }
        par[v]=u;
        sz[u]+=sz[v];
    }
};
void solve() {
    cin>>n;
    DSU dsu(n+1);
    for(i=1;i<=n;i++){
        dsu.init(i);
        st[i].push_back(i);
    }
    for(i=1;i<n;i++){
        int a,b;cin>>a>>b;
        dsu.unite(a,b);
    }
    for(i=1;i<=n;i++){
        if(st[i].size()==n){
            for(auto u:st[i]) cout<<u<<' ';
            return;
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}