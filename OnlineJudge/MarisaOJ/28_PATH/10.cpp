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
    vector<int>ti(n+1,0);
    vector<vector<int>>activated(1001);
    for(i=1;i<=n;i++)dist[i][i]=0;
    for(i=1;i<=n;i++){
        int t;cin>>t;
        ti[i]=t;
        activated[t].push_back(i);
    }
    for(i=1;i<=m;i++){
        int a,b,w;cin>>a>>b>>w;
        dist[a][b]=dist[b][a]=w;
    }
    cin>>q;
    vector<int>ans(q+1,0);
    struct Query{int x,y,id;};
    vector<vector<Query>>queries(1001);
    for(i=1;i<=q;i++){
        int x,y,t;cin>>x>>y>>t;
        queries[t].push_back({x,y,i});
    }
    for(int t=0;t<=1000;t++){
        for(auto k:activated[t]){
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
        for(auto&[x,y,id]:queries[t]){
            if(ti[x]>t||ti[y]>t) {ans[id]=-1;continue;}
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