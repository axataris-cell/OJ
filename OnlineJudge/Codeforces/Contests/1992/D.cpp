#include <bits/stdc++.h>
#include <chrono>

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

/*
1
6 2 15
LWLLCC
*/

void testcase() {
	int n, m, k; cin >> n >> m >> k; // <= k met boi
	string s; cin >> s; s = s + 'L';
	// <= m met nhay
	int dp[n + 100]; // số mét k ít nhất bơi để qua được dp[i]
	for (int i = 1; i <= n; i++) dp[i] = INT_MAX;
	dp[0] = 0;
	for (int i = 1; i <= m; i++) {
		if (s[i - 1] != 'C') dp[i] = 0;
		if (s[i - 1] == 'W') dp[i] = 1;
	}

	for (int i = m + 1; i <= n + 1; i++) {
		int jump = 0;
		dp[i] = dp[i - 1];
		for (int j = i - m; j < i; j++) {
			if (s[j - 1] == 'L') {
				dp[i] = min(dp[i], dp[j]);
				jump = max(jump, j);
			}
		}
		if (s[i - 1] == 'W') ++dp[i];
		if (s[i - 1] == 'C' && i + 1 - m > jump) dp[i] = -INT_MAX;
	}
//	for (int i = 0; i <= n + 1; i++) cout << dp[i] << ' ';
//	cout << el;
	if (dp[n + 1] <= k && dp[n + 1] >= 0) cout << "YES" << el;
	else cout << "NO" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
