#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "PalinPath"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+1,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
vector<pair<int,int>>g[MAXN];
int sz[MAXN],mask[MAXN],heavy[MAXN], tin[MAXN],tout[MAXN],at[MAXN],depth[MAXN];
const int MAXMASK=1<<26;
int res[MAXN];
int best[MAXMASK];
int timeDfs=0;
void pre(int u,int p){
    sz[u]=1;
    tin[u]=++timeDfs;
    at[timeDfs]=u;
    for(auto [v,w]:g[u]){
        if(v==p)continue;
        mask[v]=mask[u]^w;
        depth[v]=depth[u]+1;    
        pre(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[heavy[u]])heavy[u]=v;
    }
    tout[u]=timeDfs;
}
void dfs(int u,int p,bool keep){
    for(auto [v,w]:g[u]){
        if(v==p||v==heavy[u])continue;
        dfs(v,u,false);
    }
    if(heavy[u])dfs(heavy[u],u,true);
    int m=mask[u];
    if(best[m]!=-1)res[u]=max(res[u],best[m]-depth[u]);
    for(int k=0;k<26;k++){
        int x=m^(1<<k);
        if(best[x]!=-1)res[u]=max(res[u],best[x]-depth[u]);
    }
    best[m]=max(best[m],depth[u]);
    for(auto [v,w]:g[u]){
        if(v==p||v==heavy[u])continue;
        for(int t=tin[v];t<=tout[v];t++){
            int x=at[t],mx=mask[x];
            if(best[mx]!=-1)res[u]=max(res[u],depth[x]+best[mx]-2*depth[u]);
            for(int k=0;k<26;k++){
                int y=mx^(1<<k);
                if(best[y]!=-1)res[u]=max(res[u],depth[x]+best[y]-2*depth[u]);
            }
        }
        for(int t=tin[v];t<=tout[v];t++){
            int x=at[t];
            best[mask[x]]=max(best[mask[x]],depth[x]);
        }
    }
    if(!keep){
        for(int t=tin[u];t<=tout[u];t++){
            int x=at[t];
            best[mask[x]]=-1;
        }
    }
}
void solve() {
    cin>>n;
    for(i=1;i<n;i++){
        int a,b;cin>>a>>b;
        char c;
        cin>>c;
        int v= c-'a';
        g[a].push_back({b,1<<v});
        g[b].push_back({a,1<<v});
    }
    pre(1,1);
    for(i=0;i<MAXMASK;i++)best[i]=-1;
    dfs(1,1,true);
    for(i=1;i<=n;i++)cout<<res[i]<<' ';
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}