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
#define int long long

const int MAXN = 1e5 + 5;
const int INF = 2e18;

vector<int> ST(4 * MAXN, INF);

void update(int id, int l, int r, int pos, int val) {
	if (l > pos || r < pos) return;
	if (l == r) {
		ST[id] = min(ST[id], val);
		return;
	}
	
	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	
	ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return INF;
	if (x <= l && r <= y) {
		return ST[id];
	}
	int mid = (l + r) / 2;
	return min(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
}

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	vector<vector<pll>> doan(n + 1, vector<pll>());
	for (int i = 1; i <= q; i++) {
		int l, r, c; cin >> l >> r >> c;
		doan[r].push_back({l, c});
	}
	
	vector<int> dp(n + 1, INF);
	
	update(1, 0, n, 0, 0);
	dp[0] = 0;

	for (int r = 1; r <= n; r++) {
		for (auto [l, c] : doan[r]) {
			int best = query(1, 0, n, l - 1, r - 1);
			
			if (best == INF) continue;
			
			dp[r] = min(dp[r], best + c);
		}
		update(1, 0, n, r, dp[r]);
	}
	
	if (dp[n] != INF) cout << dp[n];
	else cout << -1;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
