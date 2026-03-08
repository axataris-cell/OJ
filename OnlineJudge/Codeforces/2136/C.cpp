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
	int n, k; cin >> n >> k;
	vector<int> a(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int value = a[k];
	sort(a.begin() + 1, a.begin() + n + 1);
	
	bool check = true;
	
	int idx = upper_bound(a.begin() + 1, a.begin() + n + 1, value) - a.begin();
	cerr << idx << el;
	
	int ti = 0;
	for (int i = idx; i <= n; i++) {
		if (abs(a[i] - a[i - 1]) > a[i - 1] - ti) {
			check = false;
			break;
		} else {
			ti += abs(a[i] - a[i - 1]);
		}
	}
	
	if (check) cout << "YES" << el;
	else cout << "NO" << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
