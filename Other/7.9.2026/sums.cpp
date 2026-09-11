#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "sums"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;

int dp[2][75][70005];

void testcase() {
    int n; cin >> n;

    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end(), greater<int>()); // dam bao thu tu tu dien

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int s = 70001; s >= 0; s--) {
            dp[0][i][s] = dp[0][i - 1][s] + dp[1][i - 1][s];
        }
        for(int s = 70001; s >= 0; s--) {
            if (s - a[i] >= 0) {
                dp[1][i][s] += dp[0][i][s - a[i]];
            }
        }
    }

    int res1=0,res2=-1,res3=0;
    for(int s = 1; s <= 70001; s++) {
        if (dp[0][n][s] || dp[1][n][s]) ++res1;
    }

    for(int s = 1; s <= 70001; s++) {
        if (dp[0][n][s] + dp[1][n][s] >= res3) {
            res3 = dp[0][n][s] + dp[1][n][s];
            res2 = s;
        }
    }

    cout << res1 << el;
    cout << res2 << ' ' << res3 << el;

    {
        vector<int> res;
        int cur = res2;
        int last = n;
        while (cur != 0) {
            for(int i = last; i >= 1; i--) {
                if (dp[1][i][cur]) {
                    res.push_back(i);
                    cur -= a[i];
                    last = i - 1;
                    break;
                }
            }
        }
        for(auto i : res) {
            cout << a[i] << ' ';
        }
    }
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}