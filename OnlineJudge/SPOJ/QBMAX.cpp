#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int A[105][105] = {};
int dp[105][105] = {}; // Định nghĩa: dp[i][j] chính là tổng (lớn nhất) cho đường đi tối ưu tối ô i, j.

void testcase() {
	int m, n; cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i <= m; i++) A[i][0] = 0;
	for (int j = 0; j <= n; j++) A[0][j] = 0;
	
	for (int i = 1; i <= m; i++) dp[i][1] = A[i][1];
	
	for (int j = 2; j <= n; j++) { // for theo cột
		// Cách làm: thay vì truy vấn tiến lên ta sẽ truy vấn ngược lại (mình đéo hiểu tư duy dp)
		for (int i = 1; i <= m; i++) {
			dp[i][j] = A[i][j] + dp[i][j-1];
			if (i > 1) dp[i][j] = max(dp[i][j], A[i][j] + dp[i-1][j-1]);
			if (i < m) dp[i][j] = max(dp[i][j], A[i][j] + dp[i+1][j-1]);
		}
	}
	
	int ans = dp[1][n];
	for (int i = 2; i <= m; i++) {
		ans = max(ans, dp[i][n]);
	}
	
	cout << ans;
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
