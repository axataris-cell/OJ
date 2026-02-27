#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

#define FILENAME ""

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	if (FILE *f = fopen(FILENAME".INP", "r")) {
		fclose(f);
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
}

const int MOD = 100;

void testcase() {
	int n; cin >> n;
	vector<ll> a(n + 1), f(n + 1, 0);
	vector<vector<ll>> dp(n + 5, vector<ll>(n + 5, LINF));
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][i] = 0;
		f[i] = f[i - 1] + a[i]; f[i] %= MOD;
	}

	for (int len = 2; len <= n; len++) {
		for (int r = len; r <= n; r++) {
			int l = r - len + 1;
			for (int k = l; k < r; k++) {
				int left = ((f[k] - f[l - 1]) + MOD) % MOD;
				int right = ((f[r] - f[k]) + MOD) % MOD;
//				cout << l << ' ' << r << ' ' << left << ' ' << right << el;
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + left * right);
			}
		}
	}
	
	cout << dp[1][n];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
