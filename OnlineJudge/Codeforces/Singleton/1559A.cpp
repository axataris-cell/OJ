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
const int LOG = 30;
void testcase() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(LOG + 1, -1));
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		int k = 0;
		while (x > 0 && k <= LOG) {
			a[i][k] = x & 1;
			x >>= 1;
			++k;
		}
	}
	int res = 0;
	for (int j = 0; j <= LOG; j++) {
		int cur = 1;
		for (int i = 0; i < n; i++) {
			if (a[i][j] == -1) {
				cur = 0;
				continue;
			}
			cur = cur & a[i][j];
		}
		res += cur << j;
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
