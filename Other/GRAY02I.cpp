#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "GRAY02I"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    int k;
    cin >> n >> k;
    vector<int>h(n + 1,0),v(n+1,0);
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(i=1;i<=n;i++){
        cin>>v[i];
    }
    
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}