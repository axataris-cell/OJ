#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FImexAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FImexAME".INP","r")) fclose(f),freopen(FImexAME".INP","r", stdin),freopen(FImexAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    int mx = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    sort(a.begin() + 1, a.end());

    int mex = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == mex) mex++;
    }

    cout << ((min(mex, mx) & 1) ? "Alice" : "Bob") << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}