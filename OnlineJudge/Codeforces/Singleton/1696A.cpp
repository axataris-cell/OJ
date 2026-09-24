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
const int LOG = 41;
void testcase() {
	int n, z; cin >> n >> z;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 0; j <= LOG; j++) {
			if (!(k >> j & 1) && z >> j & 1) k += 1 << j;
		}
		mx = max(mx, k);
	}
	cout << mx << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
