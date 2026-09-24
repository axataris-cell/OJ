#include <bits/stdc++.h>
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
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (n == 1) {
		cout << 1 << el;
		return;
	}
	
	int mex = 0;
	int cnt = 1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] + 1 == a[i + 1]) {
			++cnt;
		} else if (a[i] + 1 < a[i + 1]) {
			mex = max(mex, cnt);
			cnt = 1;
		}
	}
	mex = max(mex, cnt);
	cout << mex << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
