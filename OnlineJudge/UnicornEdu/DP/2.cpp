#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int dp[1005][10005];

void testcase() {
	int n, m;
	cin >> n >> m;
	
	vector<int> w(n + 1), v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	
	int j = m;
	vector<int> res;
	for (int i = n; i >= 1; i--) {
		if (dp[i][j] != dp[i - 1][j]) {
			res.push_back(i);
			j -= w[i];
		}
	}
	
	reverse(res.begin(), res.end());
	
	cout << dp[n][m] << el;
	cout << res.size() << el;
	for (auto x : res) {
		cout << x << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
