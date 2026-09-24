#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "2258B1"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, m; cin >> n >> m;
    vector<int> mp(m + 1, 0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        ++mp[x];
    }
    vector<int> suf(m + 2,0);
    for(int i = m; i >= 1; i--) {
        suf[i] = suf[i + 1] + mp[i];
    }
    vector<int> ans(m + 1, 0);
    int full = 0;
    {
        for(int L = 1; L <= m; L++) {
            int s= 0 ;
            for(int i = 1; i * L <= m; i++) {
                s += suf[i * L];
            }
            full = max(full, s);
        }
    }
    int mxk = min(m, 40LL);
    for(int k = 1; k < mxk; k++) {
        int P = (1LL << k) - 1, best=0;
        for(int L = 1; L <= m; L++) {
            int s =0;
            int lim=min(P, m/L);
            for(int j = 1; j <= lim; j++) s += suf[j*L];
            if ((1LL << k)*L <= m) s += mp[(1<<k)*L];
            best=max(best,s);
        }
        ans[k]=best;
    }
    for(int i = mxk; i <= m; i++) {
        ans[i] = full;
    }
    for(int i = 1; i <= m; i++) {
        cout << ans[i] << ' ';
    }
    cout << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}