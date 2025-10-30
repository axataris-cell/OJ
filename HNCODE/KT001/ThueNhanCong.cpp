#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

// Bài này dp thôi (sặc mùi dp)
using namespace std;

void file() {
	freopen("PROJECT.INP", "r", stdin);
	freopen("PROJECT.OUT", "w", stdout);
}

const int MAXN = 4*1e5 + 5;
int A[MAXN] = {};
ll dp[MAXN] = {};

void testcase() {
	int n; cin >> n;
	int h, s, d; cin >> h >> s >> d;
	for (int i = 1; i <= n; i++) cin >> A[i]; // Số nhân công cần
	
	dp[1] = A[1]*h + A[1]*s;
//	cout << 1 << ' ' << dp[1] << el;
	
	int cur = A[1]; // Tính số nhân viên hiện tại để lương
	for (int i = 2; i <= n; i++) {
		if (A[i] > cur) {
			dp[i] = dp[i - 1] + h*(A[i] - cur) + s*A[i];
			cur = A[i];
			
//			if (h*(A[i] - A[i - 1]) + s*A[i] > s*cur) {
//				dp[i] = dp[i - 1] + s*cur;
//			} else {
//				cur = A[i];
//				dp[i] = dp[i - 1] + h*(A[i] - A[i - 1]) + s*cur;
//			}
		} else if (A[i] < cur) {
			if (d*(cur - A[i]) + s*A[i] > s*cur) {
				dp[i] = dp[i - 1] + s*cur;
			} else {
				dp[i] = dp[i - 1] + d*(cur - A[i]) + s*A[i];
				cur = A[i];
			}
		} else {
			dp[i] = dp[i - 1] + s*cur;
		}
//		cout << i << ' ' << dp[i] << el;
	}
	
	cout << (ll)(dp[n] + d*cur);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
