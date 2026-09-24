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

#define int long long

void testcase() {
	int n; cin >> n;
	vector<int> a(n + 2, 0), b(n + 2, 0), fb(n + 2, 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		fb[i] = fb[i - 1] + b[i];
	}
	
	sort(a.begin() + 1, a.begin() + n + 1, greater<int>());
	
//	for (int i = 1; i <= n; i++) cout << fb[i] << ' ';
//	cout << el;
	
	int cur = 0;
	int res = 0;
	int idx = 1;
	while (idx <= n) {
		cur = a[idx];
		while (a[idx + 1] == cur && idx <= n) {
			++idx;
		}
		auto search = upper_bound(fb.begin() + 1, fb.begin() + n + 1, idx) - fb.begin() - 1;
		res = max(res, search * cur);
		++idx;
	}
	
	cout << res << el;
}

/*
1
3
1 3 4
2 1 1
*/
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
