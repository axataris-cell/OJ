#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "RENAME"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<int> P(n + 1,1), H(n + 1,0);
    for(int i = 1; i <= n ;i++) {
        P[i] = P[i - 1] * BASE;
        H[i] = H[i - 1] * BASE + s[i];
        P[i] %= MOD;
        H[i] %= MOD;
    }
    for(int i = 1; i <= n;) {
        int l = 0, r = n - i + 1;
        while (l <= r) {
            int len = (l + r) / 2;
            
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}