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

void testcase() {
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); //lo?i
	vector<vector<int>> f(n + 1, vector<int>(k + 1, 0)); // t?ng
	vector<vector<int>> wei(n + 1, vector<int>(k + 1, 0));
	
	int res = 0;
	
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			wei[i][j] = wei[i - 1][j];
			dp[i][j] = dp[i - 1][j];
			if (a[i] > dp[i - 1][j] && wei[i - 1][j] + a[i] <= ) {
			}
			if (j - a[i] >= 0 &&) { //f
				dp[i][j] = max(dp[i - 1][j - a[i]], dp[i][j]);
			}
			f[i][j] = f[i - 1][j] + dp[i][j];
		}
	}
	
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			cout << dp[i][j] << ' ';
		}
		cout << el;
	}
	
	for (int i = 1; i <= n; i++) {
		res = max(res, f[i][k]);
	}
	
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
