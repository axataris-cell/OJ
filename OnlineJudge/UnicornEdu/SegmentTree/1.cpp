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
int	f[4 * MAXN] = {};
int a[MAXN];

void update(int id, int pos, int val, int l, int r) {
	if (pos < l || pos > r) return;
	if (l == r) {
		f[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, pos, val, l, mid);
	update(id * 2 + 1, pos, val, mid + 1, r);
	
	f[id] = f[id * 2] + f[id * 2 + 1];
}

int get(int id, int u, int v, int l, int r) {
	if (v < l || u > r) return 0;
	if (u <= l && r <= v) {
		return f[id];
	}
	int mid = l + (r - l) / 2;
	return get(id * 2, u, v, l, mid) + get(id * 2 + 1, u, v, mid + 1, r);
}

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			int diff = y - a[x];
			a[x] = y;
			update(1, x, diff, 1, n);
		} else if (t == 2) {
			cout << get(1, x, y, 1, n) << el;
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
