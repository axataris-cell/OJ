#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define FILENAME "A"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
int cnt2(int v){
    int cnt=1;
    while(v%2==0&&v>0){
        v/=2;
        cnt*=2;
    }
    return cnt; 
}
int last(int v){
    while(v>0&&v%2==0){
        v/=2;
    }
    return v;
}
void solve() {
    cin>>n;
    vector<int>a(n+1,0);
    vector<int>f(n+1,0);
    for(i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+cnt2(a[i]);
        a[i]=last(a[i]);
    }
    // for(i=1;i<=n;i++)cout<<f[i]<<' ';
    cin>>q;
    while(q--){
        int x;cin>>x;
        int pos=lower_bound(f.begin()+1,f.end(),x)-f.begin();
        cout<<a[pos]<<el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}