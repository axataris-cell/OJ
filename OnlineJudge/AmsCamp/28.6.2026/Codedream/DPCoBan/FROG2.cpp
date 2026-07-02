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
#define INF 1e9
void testcase() {
	int n, k; cin >> n >> k;
	vector<int> a(n + 1);
	vector<int> dp(n + 1, INF);
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 0;
	dp[2] = abs(a[2] - a[1]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j >= 1) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
		}
	}
	cout << dp[n];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
