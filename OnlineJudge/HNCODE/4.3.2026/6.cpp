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

struct dat{
	int l, v, c;
	// left value cost
};

void testcase() {
	int n, m; cin >> n >> m;
	vector<int> cost(n + 1), f(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		f[i] = f[i - 1] + cost[i];
	}
	vector<dat> seg[n + 1];
	for (int i = 1; i <= m; i++) {
		int l, r, v; cin >> l >> r >> v;
		seg[r].push_back({l, v, f[r] - f[l - 1]});
	}
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		
	} 
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
