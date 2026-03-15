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

const int MAXN = 1e5 + 5;

vector<ll> ST(4 * MAXN, 0), lz(4 * MAXN, 0);

void push(int id, int l, int r) {
	if (lz[id] == 0) return;
	
	int mid = (l + r) / 2;
	
	ST[id << 1] += (mid - l + 1) * lz[id];
	lz[id << 1] += lz[id];
	
	ST[id << 1 | 1] += (r - mid) * lz[id];
	lz[id << 1 | 1] += lz[id];
	
	lz[id] = 0;
}

void update(int id, int l, int r, int x, int y, int val) {
	if (r < x || l > y) return;
	if (x <= l && r <= y) {
		ST[id] += (r - l + 1) * val;
		lz[id] += val;
		return;
	}
	
	int mid = (l + r) / 2;
	push(id, l, r);
	
	update(id << 1, l, mid, x, y, val);
	update(id << 1 | 1, mid + 1, r, x, y, val);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

ll query(int id, int l, int r, int x, int y) {
	if (r < x || l > y) return 0;
	if (x <= l && r <= y) {
		return ST[id];
	}
	
	int mid = (l + r) / 2;
	push(id, l, r);
	
	return query(id << 1, l, mid, x, y) + query(id << 1 | 1, mid + 1, r, x, y);
}

void testcase() {
	int n, q; cin >> n >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, val;
			cin >> l >> r >> val;
			update(1, 1, n, l, r, val);
		} else {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << el;
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
