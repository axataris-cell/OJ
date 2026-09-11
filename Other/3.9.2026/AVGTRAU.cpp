#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "AVG"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

#define ld long double
void testcase() {
    int n, L; cin >> n >> L;

    vector<ld>a(n + 1, 0), f(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }

    ld res = 0;
    ld l = -1e9, r = 1e9;

    vector<ld> b(n + 1, 0);
    auto check=[&](ld mid) -> bool {
        for (int i = 0; i <= n; i++){
            b[i] = f[i] - mid * i;
        }
        ld mn = 0;
        for (int i = L; i <= n; i++){
            if (b[i] - mn >= 0) return true;
            mn = min(mn, b[i - L + 1]);
        }
        return false;
    };

    while ((r - l) > 1e-7){
        ld mid = (l + r) / 2;

        if (check(mid)){
            res = mid;
            l = mid + 1e-7;
        } else r = mid - 1e-7;
    }

    cout << fixed << setprecision(6) << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}