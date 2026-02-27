#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	
	for (int j = 0; j <= n; j++) {
		dp[j][1] = j;
	}
	
	for (int num = 2; num <= n; num++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				for (int num2 = 1; num2 < num; num2++) {
					dp[i][num] = max(dp[i][num], dp[j][num2] * dp[i - j][num - num2]);
				}
			}
		}
	}
	
	int res = 0;
	
	for (int i = 2; i <= n; i++) {
		res = max(res, dp[n][i]);
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
