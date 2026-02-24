#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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
	int n; cin >> n;
	vector<int> t(n + 1), r(n + 1);
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 2; i <= n; i++) cin >> r[i];
	
	vector<vector<int>> dp(2, vector<int>(n + 1, INF));
	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = t[1];
	
	for (int i = 2; i <= n; i++) {
		dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]) + t[i];
		dp[1][i] = min(dp[0][i - 2], dp[1][i - 2]) + r[i];
	}
	
	cout << min(dp[0][n], dp[1][n]);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
