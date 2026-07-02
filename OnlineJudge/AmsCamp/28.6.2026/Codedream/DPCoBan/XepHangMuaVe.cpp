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
	vector<int> t(n + 1), r(n);

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	for (int i = 1; i < n; i++) {
		cin >> r[i];
	}
	
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0; dp[1] = t[1];
	
	for (int i = 2; i <= n; i++) {
		dp[i] = min(dp[i - 1] + t[i], dp[i - 2] + r[i - 1]);
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
