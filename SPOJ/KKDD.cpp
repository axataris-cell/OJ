#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    if(!(cin >> N >> K)) return 0;
    vector<int> a(N+1);
    for(int i=1;i<=N;i++) cin >> a[i];

    vector<vector<ll>> cost(N+2, vector<ll>(N+2, 0));

    for(int l=1;l<=N;l++){
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<int>> upper;
        ll sumLower = 0, sumUpper = 0;
        for(int r=l;r<=N;r++){
            int x = a[r];
            if(lower.empty() || x <= lower.top()){
                lower.push(x);
                sumLower += x;
            } else {
                upper.push(x);
                sumUpper += x;
            }
            while((int)lower.size() < (int)upper.size()){
                int v = upper.top(); upper.pop();
                sumUpper -= v;
                lower.push(v);
                sumLower += v;
            }
            while((int)lower.size() > (int)upper.size() + 1){
                int v = lower.top(); lower.pop();
                sumLower -= v;
                upper.push(v);
                sumUpper += v;
            }
            int med = lower.top();
            ll szL = (ll)lower.size();
            ll szU = (ll)upper.size();
            ll c = (ll)med * szL - sumLower + sumUpper - (ll)med * szU;
            cost[l][r] = c;
        }
    }

    // DP tùm lum
    vector<ll> dp(N+1, INF);
    dp[0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            int len = i - j + 1;
            if(len < K) continue;
            dp[i] = min(dp[i], dp[j-1] + cost[j][i]);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
