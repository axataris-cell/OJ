#include <bits/stdc++.h>
#define int long long
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "7"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
vector<pii>g[MAXN];
void solve() {
    cin>>n>>m;
    for(i=1;i<=m;i++){int a,b,c;cin>>a>>b>>c;
    g[a].push_back({b,c});g[b].push_back({a,c});}
    pqueue<pii,vector<pii>,greater<pii>>pq;
    vector<int> dist(n+1,INF),used(n+1,0);
    dist[1]=0;
    pq.emplace(0,1);    
    while(pq.size()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        // cout<<u<<el;
        for(auto &[v,w]:g[u]){
            int nd=dist[u]+min(used[u],w);
            if(dist[v]>nd) {
                dist[v]=nd;
                used[v]=max(used[u],w);
                pq.emplace(dist[v],v);
            }
            // cout<<v<<' '<<dist[v]<<el;
        }
    }
    cout<<(dist[n]==INF?-1:dist[n]);
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}