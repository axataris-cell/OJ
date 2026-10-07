#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1927A"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    string s; cin >> s;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) if (s[i] == 'B') {
        l = i;
        break;
    }
    for (int i = n - 1; i >= 0; i--) if (s[i] == 'B') {
        r = i;
        break;
    }
    cout << (l == -1 ? 0 : (r - l + 1)) << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}