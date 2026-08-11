#include <bits/stdc++.h>
#define int long long
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "test1"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n>>m;
    vector<vector<pii>>g(n+1);
    for(i=1;i<=m;i++){
        int a,b,w;cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    vector<int>dist(n+1,INF);
    vector<int>par(n+1,-1);
    pqueue<pii,vector<pii>,greater<pii>>pq;
    dist[1]=0;pq.emplace(0,1);
    while(pq.size()){
        auto[d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        for(auto&[v,w]:g[u])dist[v]>dist[u]+w?dist[v]=dist[u]+w,par[v]=u,pq.emplace(dist[v],v),0:0;
    }
    if(dist[n]==INF){cout<<-1<<el;return;}
    int cur=n;
    vector<int>res={cur};
    while(par[cur]!=-1){
        cur=par[cur];
        res.push_back(cur);
    }
    reverse(res.begin(),res.end());
    cout<<dist[n]<<el;
    for(auto u:res)cout<<u<< ' ';
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}