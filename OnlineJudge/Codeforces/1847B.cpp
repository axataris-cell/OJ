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

const int LOG = 30;

void testcase() {
	int n; cin >> n;
	vector<int> a(n);
	ll smol = (1LL << LOG) - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		smol &= a[i];
	}
	
	if (smol != 0) {
		cout << 1 << el;
		return;
	}
	
	int res = 0;
	ll cur = (1LL << LOG) - 1;
	for (int i = 0; i < n; i++) {
		cur &= a[i];
		if (cur == smol) {
			++res;
			cur = (1LL << LOG) - 1;
		}
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
