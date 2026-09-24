#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "C"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    int x,y;cin>>x>>y;
    vector<int>a(n+1,0);
    for(i=1;i<=n;i++)cin>>a[i];
    vector<int>g[n+1];
    for(i=1;i<=n-x;i++){
        g[i].push_back(i+x);
        g[i+x].push_back(i);
    }
    for(i=1;i<=n-y;i++){
        g[i].push_back(i+y);
        g[i+y].push_back(i);
    }
    map<int,int>comp[n+1];
    vector<int> gr(n+1,0);
    vector<bool>vis(n+1,false);
    int cur=0;
    for(i=1;i<=n;i++){
        if(!vis[i]){
            ++cur;
            queue<int>q;
            q.push(i);
            vis[i]=true;
            while(q.size()){
                int u=q.front();q.pop();
                comp[cur][a[u]]++;
                gr[u]=cur;
                for(int v:g[u]){
                    if(vis[v])continue;
                    q.push(v);
                    vis[v]=true;
                }
            }
        }
    }
    for(i=1;i<=n;i++){
        int group=gr[i];
        if(!comp[group][i]){
            cout<< "NO"<<el;
            return;
        }
    }
    cout<<"YES"<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}