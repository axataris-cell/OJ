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
	vector<ll> a(n + 1), f(n + 1, -LLONG_MAX);
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[0] = 0;
	f[1] = a[1];
	f[2] = a[2];
	ll best = f[1];
	ll res = max(f[1], f[2]);
	for (int i = 3; i <= n; i++) {
		f[i] = best + a[i];
		best = max(best, f[i - 1]);
		res = max(res, f[i]);
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
