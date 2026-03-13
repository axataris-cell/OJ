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
const int MAXN = 1e3 + 4;
vector<int> w(MAXN + 1), v(MAXN + 1), f(MAXN + 1, 0);
vector<int> ST(4 * MAXN, 0);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = v[l];
		return;
	}
	
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y) {
	if (y < l || x > r) return INF;
	if (x <= l && r <= y) {
		return ST[id];
	}
	
	int mid = (l + r) / 2;
	return min(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
}

void testcase() {
	int n, p, l; cin >> n >> p >> l;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		f[i] = f[i - 1] + w[i];
	} 
	
	build(1, 1, n);
	
	vector<int> dp(n + 1); // lưu tổng v[i] nhỏ nhất nếu chọn i là đầu xe
	for (int i = 1; i <= n; i++) {
		dp[i] = v[i];
	}
	
	for (int i = 2; i <= n; i++) {
		auto it = ...; // f[l - 1] >= f[r] - p.
		// dp[i] = dp[it] + query(1, 1, n, it, i).
	}
	
	cout << dp[n] * l;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
