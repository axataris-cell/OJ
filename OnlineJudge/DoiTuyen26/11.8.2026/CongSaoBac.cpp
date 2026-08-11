#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "CongSaoBac"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
struct Point{int x,y,id;};
void solve() {
    int k,x,y;
    cin>>n>>k>>x>>y;
    vector<Point>a(n);
    vector<Point>forx(n),fory(n);
    for(i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].id=i;
    }
    forx=fory=a;
    auto man=[&](const Point&x,const Point&y)->int{
        return abs(x.x-y.x)+abs(x.y-y.y);
    };
    {//to (n,n);
        sort(forx.begin(),forx.end(),[](const Point&x,const Point&y){
            if(x.x!=y.x)return x.x<y.x;
            else return x.y<y.y;
        });
        sort(fory.begin(),fory.end(),[](const Point&x,const Point&y){
            if(x.y!=y.y)return x.y<y.y;
            else return x.x<y.x;
        });
        deque<pair<int,int>>q;
        q.push_front({x,y});
        vector<int>dist(n,0);
        dist[{x,y}]=0;
        while(q.size()){
            auto [x,y]=q.front(); q.pop_front();
            int l=lower_bound(forx.begin(),forx.end(),x)-forx.begin();
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}