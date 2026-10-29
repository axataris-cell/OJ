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
    int n, x;cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto check = [&](int k) -> bool {
        int cnt = 0;
        int cover = -1;
        for (int i = 0; i < n; i++) {
            int l = (i > 0 && a[i] - a[i - 1] <= k);
            int r = (i < n - 1 && a[i + 1] - a[i] <= k);
            if (l || r) continue;
            if (a[i] > cover) {
                ++cnt;
                cover = a[i] + 2 * k;
                if (cnt > x) return false;
            }
        }  
        return cnt <= x;
    };

    int l = 1, r = INF, res = INF;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}