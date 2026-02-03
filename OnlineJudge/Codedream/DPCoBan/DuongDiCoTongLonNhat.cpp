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

const int MAXN = 1e3 + 5;
const int INF = 1e9;

int a[MAXN][MAXN];
int dp[MAXN][MAXN];

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) dp[i][0] = a[i][0] = -INF;
	for (int i = 1; i <= m; i++) dp[0][i] = a[0][i] = -INF;
	for (int i = 1; i <= m; i++) dp[n + 1][i] = a[n + 1][i] = -INF; 
	for (int i = 1; i <= n; i++) dp[i][1] = a[i][1];
	for (int j = 2; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = max({dp[i - 1][j - 1], dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];
		}
	}
	int res = -INT_MAX;
	for (int i = 1; i <= n; i++) res = max(res, dp[i][m]);
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
