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
	int a[n + 3][n + 3] = {};
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = cnt;
			++cnt;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res = max(res, a[i][j] + a[i - 1][j] + a[i][j - 1] + a[i + 1][j] + a[i][j + 1]);
		}
	}
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
