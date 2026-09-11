#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "C"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int x, y;
    cin >> x >> y;
    auto f =[&](int S, int x) ->int {
        int best = 0;
        int cur = 0;
        for (int i = 30; i >= 0; i--) {
            int p = (S >> i) & 1;
            int q = (x >> i) & 1;
            if (p == 1 && q == 1) {
                best = max(best, cur + (S & ((1LL << i) - 1)));
                cur |= (1LL << i);
            } else if (p == 0 && q == 1) {
                best = max(best, cur + (S & ((1LL << i) - 1)));
                break;
            }
        }
        return max(best, cur);
    };
    int best = f(x + y, x);
    
    int res1 = x + y;
    int res2 = x - best;
    
    cout << res1 << ' ' << res2 << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}