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
    int n;cin >> n;

    vector<int> a(n + 2);
    a[0] = a[n + 1] = 1;
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> dp(n + 2, vector<ll>(n + 2, 0));

    for (int len = 2; len <= n + 1; len++) {
        for (int l = 0; l + len <= n + 1; l++) {
            int r = l + len;
            for (int k = l + 1; k < r; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + 1LL * a[l] * a[k] * a[r]);
            }
        }
    }

    cout << dp[0][n + 1];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
