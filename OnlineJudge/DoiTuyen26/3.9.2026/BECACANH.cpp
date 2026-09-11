#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "BECACANH"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int m, n, X; cin >> m >> n >> X;
    vector<vector<int>> a(m+1,vector<int>(n+1,0));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    auto check = [&](int h) -> bool {
        int cnt = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if (a[i][j] >= h) continue;
                cnt += h - a[i][j];
                if (cnt >= X) return true;
            }
        }
        return false;
    };
    int l = 1, r = 2e18;
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}