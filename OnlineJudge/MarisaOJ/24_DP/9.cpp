#include <bits/stdc++.h>
<<<<<<< HEAD
#include <chrono>

=======
>>>>>>> 85a321061430a213a29540ef419bae15569118f2
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
<<<<<<< HEAD
=======
#define INF 1e9
#define LINF 1e18
>>>>>>> 85a321061430a213a29540ef419bae15569118f2

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
<<<<<<< HEAD
	int n; cin >> n;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	
	for (int j = 0; j <= n; j++) {
		dp[j][1] = j;
	}
	
	for (int num = 2; num <= n; num++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				for (int num2 = 1; num2 < num; num2++) {
					dp[i][num] = max(dp[i][num], dp[j][num2] * dp[i - j][num - num2]);
				}
			}
		}
	}
	
	int res = 0;
	
	for (int i = 2; i <= n; i++) {
		res = max(res, dp[n][i]);
	}
	
	cout << res;
=======
	int n, S; cin >> n >> S;
	vector<int> w(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0)); // gia tri
	
	int res = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= S; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
	
	cout << dp[n][S];
	
>>>>>>> 85a321061430a213a29540ef419bae15569118f2
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

<<<<<<< HEAD
	ll t = 1; //cin >> t;
=======
	int t = 1; //cin >> t;
>>>>>>> 85a321061430a213a29540ef419bae15569118f2
	while (t--) testcase();

	return 0;
}
