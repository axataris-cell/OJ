#include <bits/stdc++.h>
#define int long long
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "8"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    int c1,c2,c3,s,t;
    cin>>n>>c1>>c2>>c3>>s>>t;
    vector<int>a(n+1,0);
    vector<int>comp;
    for(i=1;i<=n;i++){
        cin>>a[i];comp.push_back(a[i]);
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    int m=comp.size();
    vector<vector<int>> pos(m);
    vector<int>used(m,false);
    auto getid=[&](int val)->int{
        return lower_bound(comp.begin(),comp.end(),val)-comp.begin();
    };
    for(i=1;i<=n;i++){
        int id=getid(a[i]);
        pos[id].push_back(i);
    }
    pqueue<pii,vector<pii>,greater<pii>>pq;
    vector<int>dist(n+1,INF);
    pq.emplace(0,s);
    dist[s]=0;
    while(pq.size()){
        auto [d,u]=pq.top();pq.pop();
        if(d>dist[u])continue;
        int id=getid(a[u]);
        if (!used[id])
            for(auto v:pos[id]){
                if(dist[v]>dist[u]+c3){
                    dist[v]=dist[u]+c3;
                    used[id]=true;
                    pq.emplace(dist[v],v);
                }
            }
        
        if(u!=1){
            if(dist[u-1]>dist[u]+c1){
                dist[u-1]=dist[u]+c1;
                pq.emplace(dist[u-1],u-1);
            }
        }
        if(u!=n){
            if(dist[u+1]>dist[u]+c2){
                dist[u+1]=dist[u]+c2;
                pq.emplace(dist[u+1],u+1);
            }
        }
    }

    cout<<dist[t];
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}