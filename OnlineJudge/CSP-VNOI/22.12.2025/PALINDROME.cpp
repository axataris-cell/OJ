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

int dp[1005][1005];

void testcase() {
	string s; cin >> s;
	int n = s.length();
	
	for (int i = 2; i <= n; i++) {
		for (int l = 0; l + i - 1 < n; l++) {
			int r = l + i - 1;
			if (s[l] == s[r]) dp[l][r] = dp[l + 1][r - 1];
			else {
				dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
			}
		}
	}
	
	string left = "", right = "";
	int l = 0, r = n - 1;
	
	while (l <= r) {
		if (l == r) {
			left += s[l]; break;
		} 
		
		if (s[l] == s[r]) {
			left += s[l];
			right += s[r];
			++l; --r;
		} else if (dp[l + 1][r] < dp[l][r - 1]) {
			left += s[l];
			right += s[l];
			++l;
		} else {
			left += s[r];
			right += s[r];
			--r;
		}
	}
	
	reverse(right.begin(), right.end());
	
	cout << left + right;
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
