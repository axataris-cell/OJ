#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define int long long
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
int dp[1005][1005];
void testcase() {
	int n;
	cin >> n;
	int a[n + 1][n + 1];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[1][0] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}