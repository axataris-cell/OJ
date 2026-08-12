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
set<int>mp[MAXN];
bool res[MAXN];
void dfs(int u, int p){
    mp[u].insert(a[u]);
    for(int v:g[u]){
        if(v==p)continue;
        dfs(v,u);   
        if(mp[v].size()>mp[u].size())swap(mp[u],mp[v]);
        for(auto k:mp[v]){ 
            mp[u].insert(k);
        }
    }
    for(auto k:mp[u]){
        int tar=s-k;
        if(mp[u].count(tar)){
            res[u]=true;
            return;
        }
    }
}
void solve() {
    cin>>n>>s;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    for(i=1;i<=n;i++)cout<<res[i];
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}