#include <bits/stdc++.h>
#define el '\n'
#define FILENAME "C"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    string s,t;cin>>s>>t;
    if(n==1){
        cout<<(s!=t?"NO":"YES")<<el;
        return;
    }
    s=' '+s;t=' '+t;
    vector<int>cnt0(2,0);
    for(i=1;i<=n;i++) {
        cnt0[0]+=(s[i]=='0');cnt0[1]+=(t[i]=='0');
    }
    if(cnt0[0]!=cnt0[1]){cout<<"No"<<el;return;}
    vector<vector<int>>cnt(2,vector<int>(2,0));
    for(i=1;i<=n;i+=2){
        cnt[0][0]+=(s[i]=='0');
        cnt[0][1]+=(t[i]=='0');
    }
    for(i=2;i<=n;i+=2){
        cnt[1][0]+=(s[i]=='0');
        cnt[1][1]+=(t[i]=='0');
    }
    if(cnt[0][0]!=cnt[0][1]||cnt[1][0]!=cnt[1][1]){
        cout<<"NO"<<el;return;
    }
    cout<<"yes"<<el;
}
int main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}