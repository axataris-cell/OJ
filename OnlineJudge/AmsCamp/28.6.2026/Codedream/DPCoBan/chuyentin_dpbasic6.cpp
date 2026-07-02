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
// nhu mu?i b? bi?n
#define INF 1e18
#define int long long
void testcase() {
    int n; cin >> n;

    vector<int> h(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> r[i];

    vector<vector<int>> dp(n + 1, vector<int>(3, -INF));

    dp[0][0] = dp[0][1] = -INF;
    dp[0][2] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + h[i];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + r[i];
        dp[i][2] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
