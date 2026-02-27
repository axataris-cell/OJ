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
const int MOD = 1e9 + 7;
void testcase() {
    string s;
    cin >> s;

    string t = "marisa";
    int n = s.length();
    int m = t.length();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n][m];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
