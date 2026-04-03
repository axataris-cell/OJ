#include<bits/stdc++.h>
using namespace std;
#define int long long
#define el "\n"
using pii = pair<int,int>;
#define pb push_back
#define ft first
#define sc second
#define __Zenyy__ int32_t main()
#define file(name)  freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
int dp[2005][2005];
int a[2005];
const int MOD = 123456789;
map<int,int>last;
void solve() {
	int n,k;
	cin >> n >> k;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
		}
		for(int j = 1; j <= k; j++){
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
			if (last.count(a[i])){
				dp[i][j] = ((dp[i][j] - dp[last[a[i]] - 1][j-1]) % MOD + MOD) % MOD;
			}
		}
		last[a[i]] = i;
	}
	cout << dp[n][k]%MOD << el; 
}

__Zenyy__ {
	cin.tie(0)->sync_with_stdio(0);
	ios_base::sync_with_stdio(false);
	int t = 1;
//	cin >> t;
	while(t--)solve();
	return 0;
}