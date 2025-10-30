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
ll dp[MAXN][2] = {};

void testcase() {
	int n; cin >> n;
	int h, s, d; cin >> h >> s >> d;
	for (int i = 1; i <= n; i++) cin >> A[i]; // Số nhân công cần
	
	dp[1][1] = dp[1][0] = A[1]*(h + s);
	
	for (int i = 2; i <= n; i++) {
		
	}
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
