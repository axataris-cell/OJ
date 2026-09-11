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
void testcase() {
    int n; cin >> n;
    int L; cin >> L;
    vector<long double> a(n + 1, 0), f(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    long double res = -10000000000;
    for(int i = 1; i <= n; i++) {
        for(int j = i - L; j >= 0; j--) {
            res = max(res, (f[i] - f[j]) / (i - j));
        }
    }

    cout << fixed << setprecision(6) << res;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}