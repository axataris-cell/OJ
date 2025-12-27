#include<bits/stdc++.h>
using namespace std;

int n;
long long W;
long long w[1002];
long long v[1002];
long long dp[1002][100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> W;
    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];

    for(int i = 1; i <= n; ++i) dp[i][0] = 0;
    for(int x = 0; x <= W; ++x) dp[0][x] = 0;

    for(int i = 1; i <= n; ++i){
        for(int x = 1; x <= W; ++x){
            if (w[i] > x) dp[i][x] = dp[i - 1][x];
            else dp[i][x] = max(dp[i - 1][x - w[i]] + v[i], dp[i - 1][x]);
        }
    }

    cout << dp[n][W];
}
