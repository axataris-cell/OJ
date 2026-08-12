#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "CapDoiDinhMenh"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
vector<int>g[MAXN],a(MAXN,0);
int s;
bool res[MAXN];
vector<vector<int>>par(LOG,vector<int>(MAXN,1));
int h[MAXN];
void dfs_lca(int u,int p){
    for(int v:g[u]){
        if(v==p)continue;
        par[0][v]=u;
        h[v]=h[u]+1;
        dfs_lca(v,u);
    }
}
int lca(int u,int v){
    if(h[u]<h[v])swap(u,v);
    if(h[u]!=h[v]){
        int k=h[u]-h[v];
        for(i=0;i<LOG;i++){
            if(k>>i&1)u=par[i][u];
        }
    }
    if(u==v)return u;
    for(i=LOG-1;i>=0;i--){
        if(par[i][u]!=par[i][v]){
            u=par[i][u];
            v=par[i][v];
        }
    }
    return par[0][u];
}
void col(int u,int p){
    for(int v:g[u]){
        if(v==p)continue;
        col(v,u);
        res[u]|=res[v];
    }
}
void solve() {
    cin>>n>>s;
    for(i=1;i<=n;i++)cin>>a[i];

    vector<int> val;
    for(i=1;i<=n;i++){
        val.push_back(a[i]);
    }
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    auto getid=[&](int v)->int{
        return lower_bound(val.begin(),val.end(),v)-val.begin();
    };
    auto check_exist=[&](int v)->bool{
        return binary_search(val.begin(),val.end(),v);
    };
    m=val.size();
    vector<vector<int>>pr(m+1);
    for(i=1;i<=n;i++){
        int id=getid(a[i]);
        pr[id].push_back(i);
    }

    for(i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs_lca(1,1);
    for(i=1;i<LOG;i++){
        for(j=1;j<=n;j++) par[i][j]=par[i-1][par[i-1][j]];
    }

    for(i=1;i<=n;i++){
        int target=s-a[i];
        if(!check_exist(target))continue;
        int id=getid(target);
        for(auto v:pr[id]){
            if(v==i)continue;
            int lc=lca(i,v);
            res[lc]=true;
        }
    }
    col(1,1);
    for(i=1;i<=n;i++)cout<<res[i];
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}