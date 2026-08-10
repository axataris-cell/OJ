#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define N 200005
#define K 1000005
#define INF 1000000000

struct E{int v,w;};
vector<E>g[N];
vector<pair<int,int>>q;
int sz[N],mn[K],ans=INF;
bool del[N];

void dfs(int u,int f){
    sz[u]=1;
    for(auto e:g[u])if(e.v!=f&&!del[e.v])dfs(e.v,u),sz[u]+=sz[e.v];
}

int get(int u,int f,int n){
    for(auto e:g[u])if(e.v!=f&&!del[e.v]&&sz[e.v]>n/2)return get(e.v,u,n);
    return u;
}

void go(int u,int f,int d,int x,int k){
    if(d>k)return;
    q.pb({d,x});
    for(auto e:g[u])if(e.v!=f&&!del[e.v])go(e.v,u,d+e.w,x+1,k);
}

void cal(int u,int k){
    dfs(u,0);
    int c=get(u,0,sz[u]);
    del[c]=1;
    vector<int>z;
    for(auto e:g[c]){
        if(del[e.v])continue;
        q.clear();
        go(e.v,c,e.w,1,k);
        for(auto x:q)if(mn[k-x.fi]!=INF)ans=min(ans,x.se+mn[k-x.fi]);
        for(auto x:q){
            if(mn[x.fi]==INF)z.pb(x.fi);
            mn[x.fi]=min(mn[x.fi],x.se);
        }
    }
    for(int x:z)mn[x]=INF;
    for(auto e:g[c])if(!del[e.v])cal(e.v,k);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    fill(mn,mn+k+1,INF);
    mn[0]=0;
    cal(1,k);
    cout<<(ans==INF?-1:ans);
}