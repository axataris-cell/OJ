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

#define int long long

const int MOD = 1e9 + 7;
const int MAXN = 4e3 + 5;

bool p[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) p[i] = true;
	for (int i = 2; i * i < MAXN; i++) {
		if (p[i]) {
			for (int j = i * i; j < MAXN; j += i) p[j] = false;
		}
	}
}

void testcase() {
	int n, k; cin >> n >> k;
	sieve();
	
	vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0));
	
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (p[i + j]) {
				dp[2][i]++;
			}
		}
	}
	
	for (int i = 3; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int t = 0; t <= k; t++) {
				if (p[j + t]) {
					dp[i][j] += dp[i - 1][t];
					dp[i][j] %= MOD;
				}
			}
		}
	}
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cerr << dp[i][j] << ' ';
		}
		cerr << el;
	}
	
	int res = 0;
	
	for (int j = 0; j <= k; j++) {
		res += dp[n][j];
		res %= MOD;
	}
	
	cout << res % MOD;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
