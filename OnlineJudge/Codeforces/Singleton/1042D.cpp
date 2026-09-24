#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "1042D"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

vector<int> g[MAXN];
vector<bool> nouse(MAXN,false);
int cntleaf=0;

void testcase() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        nouse[i]=false;
    }
    cntleaf=0;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (n <= 3) {
        cout << 0 << el;
        return;
    }
    int root = 1;
    int mxleaf=0;
    for(int v : g[1]) {
        if (g[v].size()==1)++mxleaf;
    }
    for(int i = 1; i <= n; i++) {
        int cnt =0 ;
        for(int v : g[i]) {
            if (g[v].size() == 1) ++cnt;
        }
        if (cnt > mxleaf) {
            root = i;
            mxleaf = cnt;
        }
    }
    for(int i = 1; i <= n; i++) {
        if (g[i].size() == 1) ++cntleaf;
    }
    cout << cntleaf-mxleaf << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}