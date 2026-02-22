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
	int n; cin >> n;
	vector<int> a(n + 1, 0);
	vector<int> dp(n + 1, 1), par(n + 1, -1);
	pii mx = {1, 1};
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				par[i] = j;
			}
		}
		if (dp[i] > mx.first) mx = {dp[i], i};
	}
	int cur = mx.second;
	vector<int> path;
	while (cur != -1) {
		path.push_back(a[cur]);
		cur = par[cur];
	}
	reverse(path.begin(), path.end());
	
	cout << path.size() << el;
	for (auto x : path) cout << x << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
