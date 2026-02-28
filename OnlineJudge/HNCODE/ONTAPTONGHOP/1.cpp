#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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
	vector<int> a(n + 1), f(n + 1, 0);
	vector<bool> ok(n + 1, 0);
	map<int, int> mp;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[i] = f[i - 1] + a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i] < f[i - 1]) continue;
		if (a[i] == f[i - 1]) {
			ok[i] = true;
		}
		int target = a[i] - f[i - 1];
		int l = i + 1, r = n;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (f[mid] - f[i] == target) {
				ok[mid] = 1;
			} else if (f[mid] - f[i] < target) {
				l = mid + 1;
			} else if (f[mid] - f[i] > target) {
				r = mid - 1;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (ok[i]) ++res;
	}
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}