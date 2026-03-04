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

#define int long long

void testcase() {
	int k = 1;
	int n; cin >> n;
	int m; cin >> m;
	vector<int> a(n + 1), f(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}
	for (int r = 1; r <= n; r++) {
		int l = r - k + 1;
		while (l >= 1 && f[r] - f[l - 1] < m) {
			--l;
		}
		k = r - l + 1;
	}
	cout << k;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
