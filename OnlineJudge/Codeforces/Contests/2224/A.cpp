#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "A"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    string s;cin>>s;
    s=' '+s;
    int res=0;
    for(i=1;i<=n;){
        if(s[i]=='*'){++i;continue;}
        j=i;
        int cnt=0;
        while(j<=n&&s[j]==s[i]){++j;++cnt;}
        res=max(res,cnt);
        i=j;
    }
    cout<<(res+1)/2<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}