#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "2033E"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), at(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        at[a[i]] = i;
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        if (a[a[i]] == i) continue;
        int pos = at[i];
        at[i] = a[i];
        at[a[a[i]]] = pos;
        swap(a[pos], a[a[i]]);
        ++res;
    }
    cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}