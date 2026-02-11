#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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

const int MAXN = 2e5 + 5;

vector<int> a(MAXN), bit(MAXN, 0);

int n, q;

void update(int pos, int val) {
	while (pos <= n) {
		bit[pos] += val;
		pos += pos & -pos;
	}
}

int query(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

void build() {
	for (int i = 1; i <= n; i++) {
		update(i, a[i]);
	}
}

void testcase() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build();
	while (q--) {
		int t, l, r; cin >> t >> l >> r;
		if (t == 1) {
			update(l, r);
		} else if (t == 2) {
			cout << query(r) - query(l - 1) << el;
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
