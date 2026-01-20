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

void testcase() {
	int m, n; cin >> m >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<bool> dp(m + 5);
	dp[0] = true;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= a[j] && dp[i - a[j]]) {
				dp[i] = true;
				break;
			}
		}
//		cout << i << ' ' << dp[i] << el;
	}
	
	for (int i = m; i >= 0; i--) {
		if (dp[i]) {
			cout << i; return;
		}
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
