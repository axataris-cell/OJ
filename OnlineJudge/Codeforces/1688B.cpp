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
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int cntl = 0;
	int mnb = 1 << 30;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1) {
			cntl++;
			continue;
		}
		if (__builtin_ctz(a[i]) < __builtin_ctz(mnb)) mnb = a[i];
	}
	if (cntl) {
		cout << n - cntl << el;
	} else {
		cout << __builtin_ctz(mnb) + n - 1 << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
