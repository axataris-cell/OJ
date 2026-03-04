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

void testcase() {
	int n, m; cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a.begin() + 1, a.begin() + n + 1);
	
	vector<int> dp(n + 1), f(n + 1);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		cerr << a[i] << ' ';
	}
	cerr << el;
	for (int i = 1; i <= n; i++) {
		dp[i] = f[i];
		if (i - m > 0) dp[i] += dp[i - m];
		cout << dp[i] << ' ';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
