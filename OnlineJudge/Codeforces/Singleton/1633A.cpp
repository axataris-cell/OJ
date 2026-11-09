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
    int n; cin >> n;
    auto cnt = [&](int x, int y) -> int {
        int c = 0;
        while (x > 0 && y > 0) {
            if (x % 10 != y % 10) ++c;
            x /= 10;
            y /= 10;
        }
        return c;
    };
    int res = -1;
    int mncnt = INF;
    {
        int cur = n;
        while (to_string(cur).size() == to_string(n).size()) {
            if (cur % 7 == 0) {
                if (mncnt > cnt(n, cur)) {
                    res = cur;
                    mncnt = cnt(n, cur);
                }
            }
            ++cur;
        }
    }
    {
        int cur = n;
        while (to_string(cur).size() == to_string(n).size() && cur > 0) {
            if (cur % 7 == 0) {
                if (mncnt > cnt(n, cur)) {
                    res = cur;
                    mncnt = cnt(n, cur);
                }
            }
            --cur;
        }
    }

    cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}