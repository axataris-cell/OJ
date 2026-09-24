#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    vector<int>b(n);
    for(i=0;i<n;i++)cin>>b[i];
    multiset<int> pos,neg;
    for(i=0;i<n;i++){
        if(b[i]>=0)pos.insert(b[i]);
        else neg.insert(b[i]);
    }
    vector<int>a(n,0);
    auto p=pos.lower_bound(1);
    if(p==pos.end()){
        cout<<"-1"<<el;
        return;
    }
    a[0]=*p;
    pos.erase(p);
    for(i=1;i<n;i++){
        int last=a[i-1];
        auto p=neg.upper_bound(-last);
        auto q=pos.begin(); // pos cu lay nho nhat thoi
        if (p==neg.end()){
            if(!pos.size()) {
                cout<<-1<<el;
                return;
            }
            a[i]=last+*q;
            pos.erase(q);
        } else {
            a[i]=last+*p;
            neg.erase(p);
        }
    }

    for(i=0;i<n;i++)cout<<a[i]<<' ';
    cout<<el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}