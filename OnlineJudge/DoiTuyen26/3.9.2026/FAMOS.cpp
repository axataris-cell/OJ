#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "FAMOS"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> mp(1e6 + 5, 0);
    int rem = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > m) ++rem;
        else {
            ++mp[a[i]];
        }
    }

    int l = 0, r = n;
    auto check = [&](int mid) ->bool {
        int cnt = 0;
        for(int v = 1; v <= m; v++) {
            if (mp[v] >= mid) continue;
            cnt += mid - mp[v];
        }
        return cnt <= rem;
    };
    int res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    {
        int cnt = 0;
        for(int v = 1; v <= m; v++) {
            if (mp[v] >= res) continue;
            cnt += res - mp[v];
        }
        cout << res << ' ' << cnt;
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}