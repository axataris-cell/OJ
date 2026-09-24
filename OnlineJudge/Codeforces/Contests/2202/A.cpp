#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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
	int x, y; cin >> x >> y;
	int init;
	if (y < 0) init = 4 * abs(y);
	else if (y > 0) init = 2 * abs(y);
	else init = 0;
	
	if (init > x) {
		cout << "NO" << el;
	} else {
		if ((x - init) % 3 == 0) cout << "YES" << el;
		else cout << "NO" << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
