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
vector<int> lz(4 * MAXN, 0);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void push(int id, int l, int r) {
	if (!lz[id]) return;
	
	int mid = (l + r) / 2;
	
	ST[id << 1] += lz[id] * (mid - l + 1);
	lz[id << 1] += lz[id];
	
	ST[id << 1 | 1] += lz[id] * (r - mid);
	lz[id << 1 | 1] += lz[id];
	
	lz[id] = 0;
}

void update(int id, int l, int r, int a, int b, int val) {
	if (l > b || r < a) return;
	if (l >= a && r <= b) {
		ST[id] += (r - l + 1) * val;
		lz[id] += val;
		return;
	}
	push(id, l, r);
	
	int mid = (l + r) / 2;
	update(id << 1, l, mid, a, b, val);
	update(id << 1 | 1, mid + 1, r, a, b, val);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int query(int id, int l, int r, int a, int b) {
	if (l > b || r < a) return 0;
	if (l >= a && r <= b) {
		return ST[id];
	}
	
	push(id, l, r);
	
	int mid = (l + r) / 2;
	return query(id << 1, l, mid, a, b) + query(id << 1 | 1, mid + 1, r, a, b);
}

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r, val; cin >> l >> r >> val;
			update(1, 1, n, l, r, val);
		} else if (t == 2) {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << el;
		}
	}
}

/*
6 7
0 0 0 0 0 0
1 1 6 1
2 1 3
1 4 5 2
2 4 6
2 1 4
1 1 4 1
2 1 2
*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
