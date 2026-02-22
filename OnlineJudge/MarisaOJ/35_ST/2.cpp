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

vector<int> ST(4 * MAXN, LLONG_MAX);
vector<int> a(MAXN, 0);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = a[r];
		return;
	}
	
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return;
	if (l == r) {
		ST[id] += val;
		return;
	}
	
	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	
	ST[id] = min(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return LLONG_MAX;
	if (l >= x && r <= y) {
		return ST[id];
	}
	
	int mid = (l + r) / 2;
	return min(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
}
void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
//	
//	for (int i = 1; i <= n * 4; i++) cout << ST[i] << ' ';
//	cout << el;
//	
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			update(1, 1, n, u, v);
		} else {
			cout << query(1, 1, n, u, v) << el;
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
