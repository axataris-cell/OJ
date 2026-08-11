#include <bits/stdc++.h>
#define int long long
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "10"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n>>m;
    vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
    vector<vector<pii>>g(n+1);
    vector<vector<int>>ac(1001);
    vector<int>ti(n+1,0);
    for(i=1;i<=n;i++){
        int t;cin>>t;
        ac[t].push_back(i);
        ti[i]=t;
    }
    for(i=1;i<=m;i++){
        int a,b,w;cin>>a>>b>>w;
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    cin>>q;
    struct Query{int x,y,id;};
    vector<vector<Query>>queries(1001);
    for(i=1;i<=q;i++){
        int x,y,t;cin>>x>>y>>t;
        queries[t].push_back({x,y,i});
    }
    for(i=1;i<=n;i++)dist[i][i]=0;
    vector<int>ans(q+1,INF);
    for(int curt=0;curt<=1000;curt++){
        for(auto u:ac[curt]){
            for(auto &[v,w]:g[u]){
                if(ti[v]>curt)continue;
                dist[u][v]=min(dist[u][v],w);
                dist[v][u]=min(dist[v][u],w);
            }
        }
        for(auto u:ac[curt]){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][u]+dist[u][j]);
                    dist[j][i]=dist[i][j];
                }
            }
        }
        for(auto&[x,y,id]:queries[curt]){
            ans[id]=(dist[x][y]==INF?-1:dist[x][y]);
        }
    }
    for(i=1;i<=q;i++)cout<<ans[i]<<el;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}