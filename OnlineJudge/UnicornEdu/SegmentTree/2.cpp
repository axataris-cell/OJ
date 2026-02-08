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

const int MAXN = 1e5 + 5;
vector<int> a(MAXN);
vector<int> ST(4 * MAXN, 0);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int val, int pos) {
	if (l > pos || r < pos) return;
	if (l == r) {
		ST[id] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(id << 1, l, mid, val, pos);
	update(id << 1 | 1, mid + 1, r, val, pos);
	ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return -INT_MAX - 1;
	if (l >= x && r <= y) {
		return ST[id];
	}
	int mid = (l + r) / 2;
	return max(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			update(1, 1, n, y, x);
		} else if (t == 2) {
			cout << query(1, 1, n, x, y) << el;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
