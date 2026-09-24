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

void testcase() {
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> g[max(n, m)];
	
	vector<pii> pos;
	
	int mx = -INF;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			mx = max(mx, a[i][j]);
		}
	}
	
	vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
	int tot = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool is = (a[i][j] == mx);
			if (is) ++tot;
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + is;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool is = (a[i][j] == mx);
			int sum = (f[n][j] - f[n][j - 1]) + (f[i][m] - f[i - 1][m]) - is;
			if (sum == tot) {
				cout << mx - 1 << el;
				return;
			}
		}
	}
	
//	cerr << "DEBG " << f[2][1] - f[2][0] << ' ' << f[2][1] - f[1][1] << ' ' << (a[2][1] == mx);
	
	cout << mx << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
