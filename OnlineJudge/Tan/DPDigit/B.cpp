#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "A"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int dp[101][901];
void pre(){
    dp[0][0]=1;
    for(int len=1;len<=100;len++) {
        for(int sum = 0; sum <= 900; sum++) {
            for(int d = 0; d <= 9; d++) {
                if (sum >= d) {
                    dp[len][sum] += dp[len - 1][sum - d] % MOD;
                    dp[len][sum]%=MOD;
                }
            }
        }
    }
}
bool check(string &s, int x) {
    int tot =0;
    for(auto &x:s) {
        tot += x - '0';
    }
    return tot % x == 0;
}
int count(string &s, int x) {
    int n = s.length();
    int res=0;
    int cursum=0;
    for(int i=0; i<n;i++) {
        int val = s[i]-'0';
        for(int d=0;d<val;d++){
            for(int num = x; num <= 900; num+=x) {
                int rem = num - d - cursum;
                if (rem >= 0) {
                    res += dp[n-i-1][rem];
                    res %= MOD;
                }
            }
        }
        cursum += val;
    }
    res += check(s, x);
    return res % MOD;
}
void solve() {
    pre();
    string l, r;
    cin >> l >> r;
    int x; cin >> x;
    cout << ((count(r, x) - count(l, x) + check(l, x)) % MOD + MOD) % MOD;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}