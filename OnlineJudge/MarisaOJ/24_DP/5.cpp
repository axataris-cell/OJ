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

#define int long long

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	int dp[2][2][n + 1];
	
	dp[0][0][0] = 0;
	dp[0][1][0] = 0;
	dp[1][0][0] = 0;
	dp[1][1][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		dp[0][0][i] = max(dp[1][0][i - 1], dp[1][1][i - 1]) + a[i];
		dp[1][0][i] = max(dp[0][0][i - 1], dp[0][1][i - 1]) + b[i];
		dp[0][1][i] = dp[0][0][i - 1] + a[i];
		dp[1][1][i] = dp[1][0][i - 1] + b[i];
	}
	
	cout << max({dp[0][0][n], dp[0][1][n], dp[1][0][n], dp[1][1][n]});
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
