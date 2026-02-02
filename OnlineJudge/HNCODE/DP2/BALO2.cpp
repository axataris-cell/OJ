#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int a[100005]; int v[100005];
int dp[100010][105];
void solve() {
	int n, w;
	cin >> n >> w;
	for(int i=1; i<=n; i++){
		cin >> a[i] >> v[i];
	}
	int N = 1e5 + 5;
	const int INF = 1e18;
	for(int i=0;i<=N;i++)
		for(int j=0;j<=n;j++)
	    	dp[i][j] = INF;
	for(int j=0;j<=n;j++)
    	dp[0][j] = 0;

	for(int i=1; i<=N; i++){
		for(int j=1; j<=n; j++){
			dp[i][j] = dp[i][j-1];
			if(i -v[j] >= 0){
				dp[i][j] = min(dp[i][j] , dp[i - v[j]][j-1] + a[j]);
			}
		}
	}
	int ans =0;
	for(int i=N-1; i>=1; i--){
		if(dp[i][n] <= w){
			ans = i;
			break;
		}
	}
	cout << ans;
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	ios_base::sync_with_stdio(false);
	solve();
	return 0;
}