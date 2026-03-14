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

const int MAXN = 1e5 + 5;

struct Node {
	int value;
	int count;
	
	Node(int _mn = INF, int _cnt = 0) {
		value = _mn;
		count = _cnt;
	}
	
	Node operator + (const Node &other) const {
		Node res;
		
		if (value < other.value) {
			res.value = value;
			res.count = count;
		} else if (value > other.value) {
			res.value = other.value;
			res.count = other.count;
		} else {
			res.value = value;
			res.count = count + other.count;
		}
		
		return res;
	}
};

vector<int> a(MAXN, 0);
vector<Node> ST(4 * MAXN);

void build(int id, int l, int r) {
	if (l == r) {
		ST[id].value = a[l];
		ST[id].count = 1;
		return;
	}
	
	int mid = (l + r) / 2;
	
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void update(int id, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return;
	if (l == r) {
		ST[id].value = val;
		return;
	}
	
	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

Node query(int id, int l, int r, int x, int y) {
	if (r < x || l > y) return Node();
	if (x <= l && r <= y) return ST[id];
	
	int mid = (l + r) / 2;
	return query(id << 1, l, mid, x, y) + query(id << 1 | 1, mid + 1, r, x, y);
}

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	build(1, 1, n);

	while (q--) {
		int t, u, v; cin >> t >> u >> v;
		if (t == 1) {
			update(1, 1, n, u, v);
		} else {
			Node res = query(1, 1, n, u, v);
			cout << res.value << ' ' << res.count << el;
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
