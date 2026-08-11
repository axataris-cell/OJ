#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n>>m;
    vector<int>a(n+1,0),b(m+1,0);
    vector<int>f(n+1,0);
    for(i=1;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    };
    for(i=1;i<=m;i++)cin>>b[i];
    vector<vector<int>>dp(2,vector<int>(m+1,0));
    for(i=1;i<=m;i++){
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]+a[i]);
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}