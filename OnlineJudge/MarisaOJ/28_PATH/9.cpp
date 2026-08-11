#include <bits/stdc++.h>
#define int long long
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "9"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n>>m;
    vector<vector<int>>dist(n+1,vector<int>(n+1,INF));
    for(i=1;i<=m;i++){
        int a,b,w;cin>>a>>b>>w;
        dist[a][b]=min(dist[a][b],w);
        dist[b][a]=min(dist[b][a],w);
    }
    for(i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    int best=INF;
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++){
            //cap ij=0
            int cur=0;
            for(int k=2;k<=n;k++){
                for(int l=1;l<k;l++){
                    cur+=min({dist[k][l],dist[k][i]+dist[j][l],dist[k][j]+dist[i][l]});
                }
            }
            best=min(best,cur);
        }
    }
    cout<<best;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}