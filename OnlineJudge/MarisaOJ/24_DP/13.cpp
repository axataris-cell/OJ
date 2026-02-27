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
//
//bool ispalin(string s) {
//	int n = s.length();
//	int l = 0, r = n - 1;
//	while (l <= r) {
//		if (s[l] != s[r]) return false;
//		++l;
//		--r;
//	}
//	return true;
//}

void testcase() {
	string s; cin >> s;
	int n = s.length();
	
	vector<vector<bool>> dp(n + 5, vector<bool>(n + 5, 0));
	vector<vector<bool>> full(n + 5, vector<bool>(n + 5, 0));
	
	for (int r = 1; r <= n; r++) {
		dp[r][r] = true;
	}
	
	for (int r = 2; r <= n; r++) {
		if (s[r - 1] == s[r - 2]) {
			dp[r - 1][r] = true;
			full[r - 1][r] = true;
		}
	}
	
	for (int len = 3; len <= n; len++) {
		for (int r = len; r <= n; r++) {
			int l = r - len + 1;
			if (dp[l + 1][r] && full[l + 1][r] && s[l - 1] == s[l]) {
				dp[l][r] = true;
				full[l][r] = true;
			}
			if (dp[l][r - 1] && full[l][r - 1] && s[r - 1] == s[r - 2]) {
				dp[l][r] = true;
				full[l][r] = true;
			}
			if (dp[l + 1][r - 1] && s[l - 1] == s[r - 1]) {
				dp[l][r] = true;
				full[l][r] = full[l + 1][r - 1] && (s[l - 1] == s[l]);
			}
		}
	}
//	
//	for (int r = 1; r <= n; r++) {
//		for (int l = 1; l < r; l++) {
//			if (r - l <= 1) {
//				dp[l][r] = true;
//				continue;
//			}
//			if (dp[l + 1][r] || dp[l][r - 1]) dp[l][r] = false;
//			else {
//				dp[l][r] = dp[l - 1][r - 1] && (s[l - 1] == s[r - 1]);
//			}
//		}
//	}
	
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << ((dp[l][r]) ? "YES" : "NO")<< el;
	}	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
