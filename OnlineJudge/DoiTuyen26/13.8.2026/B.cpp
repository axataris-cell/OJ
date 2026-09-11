#include <bits/stdc++.h>
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "B"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    int k;
    cin>>n>>k;
    vector<int>og(n+1,0);
    for(i=1;i<=n;i++)cin>>og[i];
    vector<int>a=og;
    int l=1,r=n;
    auto check=[&](int val)->bool{
        
    };
    int res=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
            res=mid;
        } else r=mid-1;
    }
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}