#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "XayRao"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void solve() {
    int n, q; cin >> n >> q;
    struct Dat {
        int a, b;
    };
    vector<Dat> wood(n);
    for(int i=0;i<n;i++)cin>>wood[i].a;
    for(int i=0;i<n;i++)cin>> wood[i].b;
    sort(wood.begin(),wood.end(),[](const Dat&x,const Dat&y) {
        return x.a - y.a < x.b - y.b;
    });
    
    while (q--) {
        int k; cin >> k;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}