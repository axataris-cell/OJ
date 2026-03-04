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
	int n, m; cin >> n >> m;
	vector<int> g[n + 1];
	for (int i = 1; i <= n; i++) {
		int l; cin >> l;
		for (int j = 1; j <= l; j++) {
			int x; cin >> x;
			g[i].push_back(x);
		}
	}
	map<int, bool> mp;
	for (int i = 1; i <= n; i++) {
		bool chose = false;
		for (auto x : g[i]) {
			if (!mp[x]) {
				cout << x << el;
				mp[x] = 1;
				chose = true;
				break;
			}
		}
		if (chose) continue;
		cout << 0 << el;
	}
	//TLE
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
