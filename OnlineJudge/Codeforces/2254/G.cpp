#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "G"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
int curres=0;
struct DSU{
    vector<int> sz,par,mx;
    DSU(int n):sz(n),par(n),mx(n){}
    void init(int u,vector<int>&val) {sz[u]=1,par[u]=u,mx[u]=val[u];}
    int find(int u) {
        return (u==par[u]?u:par[u]=find(par[u]));
    }
    void unite(int u, int v,bool tog) {//v->u
        u=find(u),v=find(v);
        if(u==v)return;
        par[v]=u;
        sz[u]+=sz[v];
        if(tog)curres-=min(mx[u],mx[v]);
        mx[u]=max(mx[u],mx[v]);
    }
};
vector<int>g[MAXN];
int h[MAXN];
vector<vector<int>>par(LOG,vector<int>(MAXN,1));
void dfs(int u,int p){
    for(int v:g[u]){
        if(v==p)continue;
        par[0][v]=u;
        h[v]=h[u]+1;
        for(i=1;i<LOG;i++)par[i][u]=par[i-1][par[i-1][u]];
        dfs(v,u);
    }
}
int onpath(int u,int v){
    if(h[u]<h[v])swap(u,v);
    int k=h[u]-h[v];
    for(i=0;i<LOG;i++){
        if(k>>i&1)u=par[i][u];
    }
    return(u==v?u:-1);
}
void solve() {
    cin>>n;
    for(i=1;i<=n;i++){g[i].clear();h[i]=0;}
    vector<int>val(n+1,0);
    vector<int>par(n+1,-1);
    for(i=1;i<=n;i++)cin>>val[i];
    for(i=2;i<=n;i++){
        int p;cin>>p;
        par[i]=p;
        g[p].push_back(i);
        g[i].push_back(p);
    }
    dfs(1,1);
    DSU dsu(n+1), dsu2(n+1);
    for(i=0;i<=n;i++){dsu.init(i,val);dsu2.init(i,val);}
    
    curres=0;
    vector<int>res(n+1,-1);
    for(i=1;i<=n;i++)curres+=val[i];
    res[n]=curres;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(i=1;i<=n;i++)pq.push({val[i],i});

    while(pq.size()){
        auto[val,root]=pq.top();pq.pop();
        root=dsu.find(root);
        int r2=dsu2.find(root);
        bool merged=false;
        int p=par[root];
        if(p!=-1){
            int down=dsu2.find(p);
            if(down==p){
                dsu.unite(root,p,1);
                dsu2.unite(p,root,0);
                res[pq.size()]=curres;
                continue;
            }
        }
        for(auto u:g[root]){
            int nr=dsu.find(u);
            if(u==p||nr==root)continue;
            int v=dsu2.find(u);
            int k=onpath(v,r2);
            if(k==-1)continue;
            dsu.unite((r2==k?v:r2),k,1);
            dsu2.unite(k,(r2==k?v:r2),0);
            merged=true;
            break;
        }
        if(!merged)break;
        int sz=pq.size();
        res[sz]=curres;
    }
    for(i=1;i<=n;i++)cout<<res[i]<<' ';
    cout<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}