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

#define int long long

const int MOD = 1e9 + 7;

void testcase() {
	string s; cin >> s;
	string target = "marisa";
	int n = s.length();
	int l = target.length();
	
	vector<vector<int>> dp(n + 1, vector<int>(7, 0)); // bn cac di toi chu cai thu j tai vi chi i
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			dp[i][j] = dp[i - 1][j];
			if (s[i - 1] == target[j - 1]) {
				dp[i][j] += dp[i - 1][j - 1];
			}
		}
	}
	
	cout << dp[n][l] % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
