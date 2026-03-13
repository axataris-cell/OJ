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
vector<int> w(MAXN + 1), f(MAXN + 1, 0);
vector<ld> v(MAXN + 1);
vector<ld> ST(4 * MAXN, 0);

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

ld query(int id, int l, int r, int x, int y) {
	if (y < l || x > r) return LINF;
	if (x <= l && r <= y) {
		return ST[id];
	}
	
	int mid = (l + r) / 2;
	return min(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
}

void testcase() {
	int n, p;
	ld l;
	cin >> n >> p >> l;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		f[i] = f[i - 1] + w[i];
	} 
	
	build(1, 1, n);
	
	vector<ld> dp(n + 1, LINF); // lưu tổng tg nhỏ nhất nếu chọn i là đầu xe
	dp[0] = 0;
	
	vector<int> par(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			if (f[i] - f[j - 1] > p) break;
			ld mn = query(1, 1, n, j, i);
			
			if (dp[j - 1] + l / mn < dp[i]) {
				dp[i] = dp[j - 1] + l / mn;
				par[i] = j - 1;
			}
		}
	}
	
	int cur = n;
	vector<int> path;
	while (cur != 0) {
		path.push_back(par[cur] + 1);
		cur = par[cur];
	}
	reverse(path.begin(), path.end());
	
	cout << fixed << setprecision(2) << dp[n] << el;
	for (auto x : path) cout << x << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
