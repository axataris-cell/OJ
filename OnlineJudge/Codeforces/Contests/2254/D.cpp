#include <bits/stdc++.h>
#define int long long
#define el '\n'
#define FILENAME "D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
using namespace std;
void solve() {
    cin>>n;
    vector<pair<int,int>>b(n);
    vector<pair<int, int>>comp;
    map<int, int> mp;
    for(i=0;i<n;i++){
        cin>>b[i].first;
        b[i].second=i;
        mp[b[i].first]++;
    }
    if(!mp[0]){
        cout<<-1<<el;
        return;
    }
    for(auto&[k,v]:mp){
        comp.push_back({k, v});
    }
    sort(comp.begin(),comp.end());
    sort(b.begin(),b.end());
    vector<int>a(n,0);
    int p=0;
    int lastval=0;
    m=comp.size();
    for(i=0;i<m-1;i++){
        auto [v, cnt] = comp[i];
        auto [v2, cnt2] = comp[i+1];
        int totneed=v2-v;
        int k=totneed/cnt;
        if (totneed%cnt||k<=lastval){
            cout<<-1<<el;
            return;
        }
        while(p<n&&b[p].first==v){
            int idx=b[p].second;
            a[idx]=k;
            ++p;
        }
        lastval=k;
    }
    //last
    auto [v, cnt]=comp[m-1];
    int bruh=*max_element(a.begin(),a.end());
    while(p<n&&b[p].first==v){
        int idx=b[p].second;
        a[idx]=bruh+1;
        ++p;
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