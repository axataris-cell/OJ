#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "KingArthur"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void solve() {
    int n; cin >> n;
    int A, B; cin >> A>>B;
    struct Dat {
        int a, b;
    };
    vector<Dat>ord(n);
    for(int i = 0; i <n; i++) {
        cin >> ord[i].a>>ord[i].b;
    }
    sort(ord.begin(),ord.end(),[](const Dat&x, const Dat&y) {
        return max(y.b, x.a*x.b) < max(x.b, y.a * y.b);
    });
    int res = 0;
    for(int i = 0; i < n; i++) {
        res = max(res, A / ord[i].b);
        A *= ord[i].a;
    }
    cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}