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
	int n, q; cin >> n >> q;
	vector<int> a(n + 2, 0), b(n + 2, 0), f(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
//	if (a[n] < b[n]) a[n] = b[n];
//	int mxb = 0;
//	for (int i = 2; i <= n; i++) {
//		mxb = max(mxb, b[i]);
//	}
//	
	for (int i = n; i >= 1; i--) {
		if (a[i] < b[i]) a[i] = b[i];
		if (a[i] < a[i + 1]) a[i] = a[i + 1];
	}
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] + a[i];
	}
	
	while (q--) {
		int l, r; cin >> l >> r;
		cout << f[r] - f[l - 1] << ' ';
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
