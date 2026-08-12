#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "A"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin>>n;
    vector<int>a;
    a.reserve(40*n);
    for(i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    vector<int>res;
    res.reserve(40*n);
    while(a.size()){
        int u=a.back();a.pop_back();
        if(u%2){res.push_back(u);continue;}
        a.push_back(u/2);
        a.push_back(u/2);
    }
    reverse(res.begin(),res.end());
    cin>>q;
    while(q--){
        int x;cin>>x;
        cout<<res[x-1]<<el;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}