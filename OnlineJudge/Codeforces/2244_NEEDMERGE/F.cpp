#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "F"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n;
    vector<vector<int>>g(n+1);
    for(i=2;i<=n;i++){
        int p;cin>>p;
        g[p].push_back(i);
    }
    vector<int>a(n+1,0);
    for(i=1;i<=n;i++)cin>>a[i];

    struct info{int mn,mx,sz;};
    bool ok=true;
    auto dfs=[&](auto&self,int u)->info{
        if(!g[u].size())return{a[u],a[u],1};
        int totsz=0,curmn=INF,curmx=-INF,cursz=g[u].size();
        vector<info>cc;
        for(int v:g[u]){
            info res=self(self,v);
            if(!ok)return{0,0,0};
            cc.push_back(res);
            totsz+=res.sz;
            curmn=min(curmn,res.mn);
            curmx=max(curmx,res.mx);
        }
        if(curmx-curmn+1!=totsz){ok=false;return{0,0,0};}
        if(cursz>1){
            int f=0;
            for(int i=0;i<cursz;i++){
                int ni=(i+1)%cursz;
                if(cc[i].mx+1!=cc[ni].mn)++f;
            }
            if(f>1){ok=false;return{0,0,0};}
        }
        return{curmn,curmx,totsz};
    };
    dfs(dfs,1);
    cout<<(ok?"YES":"NO")<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}