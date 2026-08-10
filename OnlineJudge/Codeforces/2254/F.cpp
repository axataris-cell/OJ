#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "F"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    vector<int>a(n,0),b(n,0);
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(a==b){
        cout<<"YES"<<el;
        return;
    }
    int xa=0,xb=0;
    for(i=0;i<n;i++){
        xa^=a[i];
        xb^=b[i];
    }
    int tar=xa^xb;
    int res=-1;
    for(i=0;i<n;i++){
        if(a[i]==tar){
            res=i;
            break;
        }
    }
    if(res==-1){
        cout<<"NO"<<el;
        return;
    }

    for(i=0;i<n;i++){
        if(i==res)continue;
        a[i]^=tar;
    }
    sort(a.begin(),a.end());

    cout<<(a==b?"YES":"NO")<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}