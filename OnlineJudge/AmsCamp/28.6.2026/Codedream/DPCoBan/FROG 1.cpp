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
#define INF 1e18

void testcase() {
    int n; 
    cin >> n;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (n == 1) {
        cout << 0;
        return;
    }

    vector<long long> dp(n + 1, INF);
    dp[1] = 0;
    dp[2] = llabs(a[2] - a[1]);

    for (int i = 3; i <= n; i++) {
        dp[i] = min(
            dp[i - 1] + llabs(a[i] - a[i - 1]),
            dp[i - 2] + llabs(a[i] - a[i - 2])
        );
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
