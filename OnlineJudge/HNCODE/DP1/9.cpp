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
	int n, s; cin >> n >> s;
	vector<ll> c(n + 1), f(10000 + 5);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		f[c[i]] = 1;
	}
	for (int i = 1; i <= s; i++) {
		for (int j = 1; j <= n; j++) {
			if (i - c[j] > 0) f[i] += f[i - c[j]];
		}
	}
	cout << f[s];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
