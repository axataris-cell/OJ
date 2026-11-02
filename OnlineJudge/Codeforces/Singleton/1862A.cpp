#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, m; cin >> n >> m;
    char g[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> g[i][j];
    }
    string samp = "vika";
    int cur = 0;
    for (int k = 0; k < m; k++) {
        if (cur >= 4) break;
        vector<int> mp(26, 0);
        for (int l = 0; l < n; l++) ++mp[g[l][k] - 'a'];
        if (mp[samp[cur] - 'a']) ++cur;
    }
    cout << (cur == 4 ? "YES" : "NO") << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}