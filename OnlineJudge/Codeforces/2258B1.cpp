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
    int best = 0;
    for(int L = 1; L <= m; L++) {
        if (L * 2 > m) best = max(best, suf[L]);
        else best = max(best, suf[L] + mp[L * 2]);
    }

    cout << best << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}