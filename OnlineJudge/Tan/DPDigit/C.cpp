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
const int INF=2e9,MAXN=2e5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int dp[101][10];
void pre() {
    for(int i = 1; i <= 9; i++) dp[1][i] = i;
    for(int len = 2;len <= 100; len++) {
        for(int d = 1; d <= 9; d++) {
            for(int x =0; x <= 9;x++) {
                dp[len][d] += dp[len - 1][x];
                dp[len][d] %= MOD;
            }
            int contri = d;
            for(int i = 1; i < len; i++) {
                contri *= 10;
                contri %= MOD;
            }
            dp[len][d] += contri;
            dp[len][d] %= MOD;
        }
    }
}
int count(string &s) {
    int tot =0;
    for(auto &c : s) tot += c - '0';
    return tot % MOD;
}
int solve(string &s) {
    int n = s.length();
    int res = 0;
    for(int i = 0; i < n; i++) {
        int val= s[i]-'0';
        for(int d =0; d < val; d++) {
            res += dp[n - i - 1][d];
            res %= MOD;
        }
    }
    res += count(s);
    return res % MOD;
}
void solve() {
    pre();
    string l, r; cin >> l >> r;
    cout << ((solve(r) - solve(l) + count(l)) % MOD + MOD) % MOD;
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}