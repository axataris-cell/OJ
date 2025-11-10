#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

void testcase() {
	string s; cin >> s;
	int n = s.size();
	
	stack<int> st;
	vector<int> dp(n, -1);
	vector<int> ans(n, -1);
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') st.push(i);
		else if (!st.empty()) {
			int open = st.top(); st.pop();
			dp[open] = i;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] != -1) {
			ans[i] = dp[i];
			if (dp[i] + 1 < n && ans[dp[i] + 1] != -1)
				ans[i] = ans[dp[i] + 1];
		}
	}
	
	int q; cin >> q;
	while (q--) {
		int x; cin >> x; x--;
		if (x < 0 || x >= n || ans[x] == -1) cout << -1 << el;
		else cout << ans[x] + 1 << el;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	//file();

	ll t = 1; 
	cin >> t;
	while (t--) testcase();
	
	return 0;
}
