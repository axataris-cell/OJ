#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "ChiaKeo"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=5e5+5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
struct eve{int x,v,type;};
vector<int>uoc[MAXN];
int cnt[MAXN];
void pre(){
    for(i=1;i<MAXN;i++){
        for(j=i;j<MAXN;j+=i)++cnt[j];
    }
    for(i=1;i<MAXN;i++)uoc[i].reserve(cnt[i]);
    for(i=1;i<MAXN;i++){
        for(j=i;j<MAXN;j+=i)uoc[j].push_back(i);
    }
}
int C[MAXN];
vector<vector<eve>>event(MAXN+1);
void solve() {
    cin>>n>>q;
    vector<int>a(n+1,0);
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=q;i++){
        int l,r,x,v;cin>>l>>r>>x>>v;
        event[l].push_back({x,v,1});
        if(r<n) event[r+1].push_back({x,v,-1});
    }
    vector<int>res(n+1,0);
    for(i=1;i<=n;i++){
        for(auto &[x,v,type]:event[i]){
            if(type==-1){
                C[x]-=v;
            }else C[x]+=v;
        }
        for(auto x:uoc[a[i]]){
            res[i]+=C[x];
        }
    }
    for(i=1;i<=n;i++)cout<<res[i]<<' ';
}
int32_t main() {
    fastio
    pre();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}