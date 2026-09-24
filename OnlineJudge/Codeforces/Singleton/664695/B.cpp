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
#define int long long
void testcase() {
	int n; cin >> n;
	vector<int> a(n + 1, 0), d(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}
	int q; cin >> q;
	while (q--) {
		int l, r, x; cin >> l >> r >> x;
		if (r < n) d[r + 1] -= x;
		d[l] += x;
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += d[i];
		cout << cur << ' ';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
