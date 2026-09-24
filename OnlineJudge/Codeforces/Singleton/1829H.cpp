#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=7,MOD=1e9+7,BASE=113,BLOCK=400;
string BIT(int v) {
	string res = "";
	for (int i = 0; i < LOG; i++) {
		if (v >> i & 1) res += '1';
		else res += '0';
	}
	return res;
}

void testcase() {
	int n; cin >> n;
	int K; cin >> K;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int dp[n + 1][2][1 << 6];
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < (1 << 6); ++k) dp[i][j][k] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int mask = 0; mask < (1 << 6); ++mask) {
			dp[i][0][mask] = dp[i - 1][1][mask] + dp[i - 1][0][mask];
			dp[i][0][mask] %= MOD;
		}
		
		for (int prev = 0; prev < 64; ++prev) {
			int ways = (dp[i - 1][0][prev] + dp[i - 1][1][prev]) % MOD;
			if (ways > 0) {
				int nmask = prev & a[i];
				dp[i][1][nmask] += ways;
				dp[i][1][nmask] %= MOD;
			}
		}
		
		dp[i][1][a[i]]++;

	}
	
	int res = 0;
	
	for (int mask = 0; mask < (1 << 6); ++mask) {
		if (__builtin_popcount(mask) == K) {
			res += dp[n][1][mask] + dp[n][0][mask];
			res %= MOD;
		}
	}
	
	cout << res % MOD << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

