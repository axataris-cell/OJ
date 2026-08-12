#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "NoiDiem"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
int res=0;
struct DSU{
    vector<int>sz,par;
    DSU(int n):sz(n),par(n){}
    void init(int u){sz[u]=1,par[u]=u;}
    int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        par[v]=u;
        --res;
    }
};
void solve() {
    cin>>n>>m;
    res=n;
    vector<vector<int>>cnt(11,vector<int>(n+1,0));
    for(i=1;i<=m;i++){
        int a,d,k;cin>>a>>d>>k;
        cnt[d][a]=max(cnt[d][a],k);
    }
    DSU dsu(n+1);
    for(i=1;i<=n;i++)dsu.init(i);
    for(int d=1;d<=10;d++){
        for(int x=1;x<=n;x++){
            if(cnt[d][x]>0){
                if(x+d<=n){
                    dsu.unite(x,x+d);
                    cnt[d][x+d]=max(cnt[d][x+d],cnt[d][x] - 1);
                }
            }
        }
    }
    cout<<res<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}