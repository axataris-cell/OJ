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
    int n, m; cin >> n >> m;
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        cnt[a]++;
    }
    vector<int> f(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        f[i] = f[i - 1] + cnt[i];
    }
    auto query = [&](int l, int r) -> int {
        l = max(1LL, l);
        r = min(m, r);
        if (l > r) return 0LL;
        return f[r] - f[l - 1];
    };
    int mxk = min(m, 18LL);
    vector<int> ans(m + 1, 0);
    for (int L = 1; L <= m; ++L) {
        int lim = m / L;
        vector<int> P0(lim + 1, 0);
        vector<int> P1(lim + 1, 0);
        for (int c = 1; c <= lim; ++c) {
            int l = c * L;
            int r = min(m, (c + 1) * L - 1);
            int cntc = query(l, r);
            P0[c] = P0[c - 1] + cntc;
            P1[c] = P1[c - 1] + c * cntc;
        }
        for (int k = 1; k <= mxk; ++k) {
            int pw = 1LL << k;
            int limit1 = min(lim, pw - 1);
            int g1 = P1[limit1];

            int g2 = 0;
            if (pw * L <= m) {
                g2 = pw * cnt[pw * L];
            }

            int g3 = 0;
            if (pw * L + 1 <= m) {
                int cnt_g3 = query(pw * L + 1, m);
                g3 = (pw - 1) * cnt_g3;
            }

            int val = g1 + g2 + g3;

            if (val > ans[k]) {
                ans[k] = val;
            }
        }
    }
    for (int k = mxk + 1; k <= m; ++k) {
        ans[k] = ans[mxk];
    }
    cout << ans[1] << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}