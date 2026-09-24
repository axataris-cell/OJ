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
const int LOG = 10;
void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	vector<bool> one(LOG, 0), zero(LOG, 1);
	int mx = -INT_MAX, mn = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
		for (int j = 0; j <= LOG; j++) {
			if (a[i] >> j & 1) one[j] = 1;
			else zero[j] = 0;
		}
	}
	// min
	for (int i = 0; i <= LOG; i++) {
		if (mn >> i & 1 && zero[i] == 0) mn -= 1 << i; 
	}
	//max
	for (int i = 0; i <= LOG; i++) {
		if (!(mx >> i & 1) && one[i] == 1) mx += 1 << i;
	}
	cout << mx - mn << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
