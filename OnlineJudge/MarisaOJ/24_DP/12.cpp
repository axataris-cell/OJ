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
const int MAXN = 705;
void testcase() {
	int a, b; cin >> a >> b;
	
	vector<vector<int>> dp(MAXN + 1, vector<int>(MAXN + 1, INF));
	
	for (int i = 1; i <= MAXN; i++) {
		dp[1][i] = i - 1;
		dp[i][1] = i - 1;
	}
	
	for (int i = 2; i <= MAXN; i++) {
		for (int j = 2; j <= MAXN; j++) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			} else {
				for (int k = 1; k < i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
				for (int k = 1; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}
	
	cout << dp[a][b];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
