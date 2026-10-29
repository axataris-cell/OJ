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
    int n, k; cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto get = [&]() -> int {
        vector<int> f;
        vector<int> mp(n + 1, 0);
        int curmex = 0;
        for (int i = 1; i <= n; i++) {
            ++mp[a[i]];
            while (mp[curmex]) ++curmex;
            f.push_back(curmex);
        }
        sort(f.begin(), f.end(), greater<int>());
        return f[k - 1];
    };

    int res[3] = {get(), -1, -1};

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            swap(a[i], a[j]);
            int cur = get();
            if (cur > res[0]) {
                res[1] = i;
                res[2] = j;
                res[0] = cur;
            }
            swap(a[i], a[j]);
        }
    }

    if (res[1] == -1) {
        cout << -1 << el;
    } else cout << res[1] << ' ' << res[2] << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}