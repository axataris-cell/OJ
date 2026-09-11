#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "APPLIMIT"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void testcase() {
    int n, m; cin >> n >> m;

    vector<int> a(n + 1),b(n + 1),s(m + 1),f(m + 1, 0);

    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        f[b[i]] += a[i];
    }
    for (int j = 1; j <= m; ++j) cin >> s[j];

    int q; cin >> q;
    vector<bool> can(n + 1, false);
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r;
            int x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; ++i) {
                int group = b[i];
                can[i] = (f[group] < s[group]);
            }
            for (int i = l; i <= r; ++i) {
                if (can[i]) {
                    a[i] += x;
                    f[b[i]] += x;
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            int mx = -INF;
            int mn = INF;
            for (int i = l; i <= r; ++i) {
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
            cout << mx << ' ' << mn << el;
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}