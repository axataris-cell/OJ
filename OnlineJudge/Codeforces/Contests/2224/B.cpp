#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "B"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    vector<int>a(n+1,0);
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<n;i++){
        if(a[i]-i<0){
            cout<<"NO"<<el;
            return;
        }
        int k=a[i]-i;
        a[i]-=k;
        a[i+1]+=k;
        // cout<<i<<el;
        // for(j=1;j<=n;j++)cout<<a[j]<<' ';
        // cout<<el;
    }
    for(i=1;i<n;i++){
        if(a[i]>=a[i+1]){
            cout<<"NO"<<el;
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