#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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
	int s; cin >> s;
	vector<int> a(n + 1);
	int mx = -INF, mn = INF;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}
	
	if (mn <= s && s <= mx) {
		cout << min(2 * (s - mn) + mx - s, 2 * (mx - s) + s - mn);
	} else {
		if (s < mn) cout << mx - s;
		else if (s > mx) cout << s - mn;
	}
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
