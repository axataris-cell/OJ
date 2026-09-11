#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "GRAY06E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin >> q >> n;
    struct Dat {
        int s,t,c;
    };
    vector<Dat> a(n);
    for(int i =0;i < n; i++) {
        cin >>a[i].s>>a[i].t>>a[i].c;
    }
    sort(a.begin(),a.end(),[](const Dat&x, const Dat&y) {
        return x.s + x.t > y.s + y.t;
    });
    int res =0;
    for(i=0;i < min(n, q);i++) {
        res += a[i].s + a[i].t;
        --a[i].c;
    }
    q -=n;
    if (q <= 0) {
        cout << res;return;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}