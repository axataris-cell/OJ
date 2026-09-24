#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "C2"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    string s,t;cin>>s>>t;
    s=" "+s,t=" "+t;

    //C1
    vector<int>cnt0(2,0);
    for(i=1;i<=n;i++) {
        cnt0[0]+=(s[i]=='0');cnt0[1]+=(t[i]=='0');
    }
    if(cnt0[0]!=cnt0[1]){cout<<"-1"<<el;return;}
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
        cout<<"-1"<<el;return;
    }
    //end
    
    int res=0;
{
    vector<int>a,b;
    for(i=1;i<=n;i+=2){
        if(s[i]=='1')a.push_back(i);
        if(t[i]=='1')b.push_back(i);
    }
    for(i=0;i<a.size();i++){
        res+=abs(b[i]-a[i]);
    }
}
{
    vector<int>a,b;
    for(i=2;i<=n;i+=2){
        if(s[i]=='1')a.push_back(i);
        if(t[i]=='1')b.push_back(i);
    }
    // for(auto x:a)cout<<x<<' ';
    // cout<<el;
    // for(auto x:b)cout<<x<< ' ';
    // cout<<el;
    for(i=0;i<a.size();i++){
        res+=abs(b[i]-a[i]);
    }
}
    cout<<res/2<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}