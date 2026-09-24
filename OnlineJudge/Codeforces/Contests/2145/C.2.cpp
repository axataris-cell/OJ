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
	string s; cin >> s;
	
	vector<int> f(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'a') f[i] = f[i - 1] + 1;
		if (s[i - 1] == 'b') f[i] = f[i - 1] - 1;
	}
	
	if (f[n] == 0) {
		cout << 0 << el;
		return;
	}
//	
//	cout << "DEBUG: ";
//	for (int i = 1; i <= n; i++) {
//		cout << f[i] << ' ';
//	}
//	cout << el;
	
	int target = f[n];
	map<int, int> mp;
	
	int res = INF;
	
	mp[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (mp.count(f[i] - target)) {
			res = min(res, i - mp[f[i] - target]);
		}
		mp[f[i]] = i;
	}
	
	if (res != INF && res != n) cout << res << el;
	else cout << -1 << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
