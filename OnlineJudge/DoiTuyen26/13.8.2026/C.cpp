#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "fishing"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n;
    struct fih{int w,d,a,id;};
    vector<fih>fish(n);
    for(i=0;i<n;i++){
        cin>>fish[i].w>>fish[i].d>>fish[i].a;
    }
    // get fishid
    vector<int>f(n);
    {
        vector<pii>comp(n);
        for(i=0;i<n;i++)comp[i]={fish[i].a,i};
        sort(comp.begin(),comp.end());
        for(i=0;i<n;i++)fish[comp[i].second].id=i;
        f[0]=comp[0].first;
        for(i=1;i<n;i++)f[i]=f[i-1]+comp[i].first;
    }
    cin>>m;
    struct cuh{int x,c;};
    vector<cuh>cun(m);
    for(i=0;i<m;i++)cin>>cun[i].x>>cun[i].c;
    sort(fish.begin(),fish.end(),[](const fih&x, const fih&y){return x.w<y.w;});
    sort(cun.begin(),cun.end(),[](const cuh&x, const cuh&y){return x.x<y.x;});
    int cost;cin>>cost;
    int res=0;
    int p=0;
    for(i=0;i<m;i++){
        auto [x,c]=cun[i];
        while(p<n&&fish[p].w<=cun[i].x){
            
            ++p;
        }

    }
    cout<<res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}