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
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int cur = 0;
	vector<int> arr;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i - 1] + 1) ++cur;
		else {
			if (a[i] == a[i - 1]) continue;
			arr.push_back(cur);
			cur = 1;
		}
	}
	arr.push_back(cur);
	int res = 0;
	for (auto x : arr) res += (x + 1) / 2;
	
	cout << res << el; 
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
