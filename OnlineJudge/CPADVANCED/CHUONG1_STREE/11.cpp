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

const int MAXN = 3e5 + 5;

vector<int> a(MAXN, 0), ST(4 * MAXN, 0);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);

	ST[id] = ST[id << 1] ^ ST[id << 1 | 1];
}

void update(int id, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return;
	if (l == r) {
		ST[id] ^= val;
		return;
	}

	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);

	ST[id] = ST[id << 1] ^ ST[id << 1 | 1];
}

int res;
void query(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return;
	if (x <= l && r <= y) {
		res ^= ST[id];
		return;
	}

	int mid = (l + r) / 2;
	query(id << 1, l, mid, x, y);
	query(id << 1 | 1, mid + 1, r, x, y);
}

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int i, val; cin >> i >> val;
			a[i] = val;
			update(1, 1, n, i, val);
		} else {
			int l, r; cin >> l >> r;
			res = a[l];
			query(1, 1, n, l, r);
			res ^= a[l];
			cout << res << el;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
