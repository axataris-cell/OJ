#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "MaximumComposition"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
void solve() {
    int n, k;
    cin >> n >> k;

    struct Dat {
        int a, b;
    };

    vector<Dat> fun(n);

    for (auto &[a, b] : fun)
        cin >> a >> b;

    sort(fun.begin(), fun.end(), [](const Dat& x, const Dat& y) {
        return x.a * y.b + x.b < y.a * x.b + y.b;
    });

    vector<int> dp(k + 1, -1);
    dp[0] = 1;

    for (auto [a, b] : fun) {
        for (int j = k - 1; j >= 0; --j) {
            if (dp[j] != -1) {
                dp[j + 1] = max(dp[j + 1], a * dp[j] + b);
            }
        }
    }

    cout << dp[k] << el;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}