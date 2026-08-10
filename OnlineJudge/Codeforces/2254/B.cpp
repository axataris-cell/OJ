#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "B"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    string s;cin>>s;
    s=" "+s;int cnt=0;
    bool a2=false,a1=false;
    for (i=1;i<=n;){
        int j=i;
        while(j<=n&&s[j]==s[i])++j;
        if(j==i+1&&i!=1&&i!=n){
            if(s[i-1]==s[i+1])a2=true;
            else a1=true;
        }
        ++cnt;
        i=j;
    }
    if(a2){cout<<cnt-2<<el;return;}
    if(a1){cout<<cnt-1<<el;return;}
    cout<<cnt<<el;  
}
int main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}