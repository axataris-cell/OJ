#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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
const int MAXN = 3e5 + 5;

/*
1
8
3 2 2 3 7 3 6 7
*/

#define int long long

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1), dp(n + 1, INF);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) dp[a[i]] = 1;
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			dp[j] = min(dp[j], dp[i] + dp[j / i]);
		}
	}
	
	for (int i = 1; i <= n; i++) cout << ((dp[i] == INF) ? -1 : dp[i]) << ' ';
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
