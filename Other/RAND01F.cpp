#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "RANDO01E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113;
int n=1,m=1,q=1,i=0,j=0;
void solve() {
    cin >>n;
    int k; cin >> k;
    vector<int> a(n + 1, 0);
    int mx = 0;
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx,a[i]);
        tot += a[i];
    }
    int l = mx;
    int r = 1e12;
    auto check=[&](int val)->bool {
        return val * k >= tot;
    };
    int res = mx;
    while (l <= r) {
        int mid = (l +r ) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else l= mid + 1;
    }
    cout << res * k - tot;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}