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

const int LOG = 31;

void testcase() {
	ll n, l; cin >> n >> l;
	vector<vector<bool>> bit(n, vector<bool>(LOG + 1, 0));
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		for (int j = 0; j <= LOG; j++) {
			bit[i][j] = x >> j & 1;
		}
	}
	ll res = 0;
	for (int j = 0; j <= LOG; j++) {
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (bit[i][j] & 1) ++cnt1;
			else ++cnt0;
		}
		if (cnt1 > cnt0) res += 1 << j;
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