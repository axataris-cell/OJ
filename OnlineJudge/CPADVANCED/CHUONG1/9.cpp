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

struct Node {
	int mx;
	int sum;
	
	Node(int _mx = -INF, int _sum = 0) {
		mx = _mx;
		sum = _sum;
	}
};

Node mergeNode(const Node &left, const Node &right) {
	Node res;
	
	res.sum = left.sum + right.sum;
	res.mx = max(left.mx, right.mx);
	
	return res;
}

vector<int> a(MAXN, 0);
vector<Node> ST(4 * MAXN);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = {a[l], a[l]};
		return;
	}
	
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void update1(int id, int l, int r, int x, int y, int val) {
	if (ST[id].mx < val || l > y || r < x) return;
	if (l == r) {
		ST[id].mx %= val;
		ST[id].sum = ST[id].mx;
		return;
	}
	
	int mid = (l + r) / 2;
	update1(id << 1, l, mid, x, y, val);
	update1(id << 1 | 1, mid + 1, r, x, y, val);
	
	ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

void update2(int id, int l, int r, int pos, int val) {
	if (l > pos || r < pos) return;
	if (l == r) {
		ST[id].mx = val;
		ST[id].sum = val;
		return;
	}
	
	int mid = (l + r) / 2;
	update2(id << 1, l, mid, pos, val);
	update2(id << 1 | 1, mid + 1, r, pos, val);
	
	ST[id] = mergeNode(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return 0;
	if (x <= l && r <= y) {
		return ST[id].sum;
	}
	
	int mid = (l + r) / 2;
	return query(id << 1, l, mid, x, y) + query(id << 1 | 1, mid + 1, r, x, y);
}

void testcase() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);
	
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l, r) << el;
		} else if (t == 2) {
			int l, r, val; cin >> l >> r >> val;
			update1(1, 1, n, l, r, val);
		} else if (t == 3) {
			int pos, val; cin >> pos >> val;
			update2(1, 1, n, pos, val);
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
