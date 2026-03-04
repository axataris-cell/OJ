#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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

const int MOD = 1e9 + 7;

void testcase() {
	int n, m, k; cin >> n >> m >> k;
	int res = 0;
	for (int x = 1; x <= k; x++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int lcm = (i * j) / __gcd(i, j);
				if (x % lcm == 0) ++cnt;
			}
		}
		res += ((cnt % MOD) * x) % MOD;
		res %= MOD;
	}
	cout << res % MOD;
	// TLE
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
