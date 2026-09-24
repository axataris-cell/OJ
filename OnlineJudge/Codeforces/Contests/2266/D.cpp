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
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        c[i] = a - (i + 1);
    }
    
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    
    int res = 1;
    int cur = 1;
    
    for (int i = 1; i < n; i++) {
        if (c[i] == c[i - 1] + 1) {
            cur++;
        } else {
            cur = 1;
        }
        res = max(res, cur);
    }
    
    cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

