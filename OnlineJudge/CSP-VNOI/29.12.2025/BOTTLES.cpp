#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define int long long
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
	int n, k; cin >> n >> k;
	vector<int> a(n + 2);
	
	int tot = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		tot += a[i];
	}
	
	vector<int> dp(n + 2, INT_MAX);
	dp[0] = 0;
	
	deque<int> dq;
	
	vector<int> prev(n + 2, -1);
	vector<bool> rek(n + 2, false);
	vector<int> ans;
	
	dq.push_back(0);
	for (int i = 1; i <= n + 1; i++) {
	    while (dq.size() && dq.front() < i - k) dq.pop_front();
	    dp[i] = dp[dq.front()] + a[i];
	    prev[i] = dq.front();

	    while (dq.size() && dp[dq.back()] >= dp[i]) {
	    	dq.pop_back();
		}
		
	    dq.push_back(i);
	}
	int i = n + 1;
	while (i != 0) {
		rek[i] = true;
		i = prev[i];
	}
	for (int i = 1; i <= n; i++) {
		if (!rek[i]) ans.push_back(i);
	}
	
	cout << ans.size() << ' ' << tot - dp[n + 1] << el;
	for (auto x : ans) cout << x << ' ';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
