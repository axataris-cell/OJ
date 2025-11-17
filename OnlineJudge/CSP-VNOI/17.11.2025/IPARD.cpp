#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define el '\n'

using namespace std;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

int dp[5005] = {}; // Số cách phân tích của phần tử i
const int MOD = 123456789;

void init() {
	dp[0] = 1;
	
	for (int i = 1; i <= 5005; i++) {
		for (int j = 5005; j >= i; j--) {
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	} 
}

void testcase() {
	int n; cin >> n;
	cout << dp[n] << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//file();
	init();
	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
