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

const int MAXN = 1e3 + 5;

ll a[MAXN][MAXN];
ll f[MAXN][MAXN];

ll getSum(int x1, int y1, int x2, int y2) {
	// x1 x2 la hang
	return f[x2][y2] - f[x1][y2] - f[x2][y1] + f[x1][y1];
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) f[i][0] = 0;
	for (int j = 1; j <= m; j++) f[0][j] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
		}
	}
	ll res = -LLONG_MAX;
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			for (int k = 0; k < i; k++) {
				for (int l = 0; l < j; l++) {
					res = max(res, getSum(i, j, k, l));
				}
			}
		}
	}
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
