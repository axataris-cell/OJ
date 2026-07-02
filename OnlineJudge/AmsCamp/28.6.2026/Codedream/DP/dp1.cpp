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

#define int long long

void testcase() {
	int n, a, b, c; cin >> n >> a >> b >> c;
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);
	// a <= b <= c
	
	vector<int> dp(4001, -INT_MAX);
	dp[0] = 0;
	dp[a] = dp[b] = dp[c] = 1;

	for (int i = a; i <= n; i++) {
		if (i >= a) dp[i] = max(dp[i - a] + 1, dp[i]);
		if (i >= b) dp[i] = max(dp[i - b] + 1, dp[i]);
		if (i >= c) dp[i] = max(dp[i - c] + 1, dp[i]);
	}
	for (int i = 0; i <= n; i++) cerr << dp[i] << ' ';
	cerr << el;
	cout << dp[n];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
