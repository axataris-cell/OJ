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

/*
1
8
4 3 3 1 10 4 9 9
*/

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<bool> dp(n + 2, 0);
	dp[0] = dp[n + 1] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (i - a[i] > 0 && dp[i - a[i] - 1]) dp[i] = true;
		if (i + a[i] <= n && dp[i - 1]) dp[i + a[i]] = true;
	}
	
	for (int i = 1; i <= n; i++) cerr << dp[i] << ' ';
	cerr << el;
	
	cout << ((dp[n]) ? "YES" : "NO") << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
