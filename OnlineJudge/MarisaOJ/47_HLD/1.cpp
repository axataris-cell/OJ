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

int n, q; 

vector<int> g[MAXN];
vector<int> heavy(MAXN, 0), sz(MAXN, 1), depth(MAXN, 0), par(MAXN, 0);
vector<int> ST(4 * MAXN, 0), og(MAXN, 0), pos(MAXN, 0), head(MAXN, 0);
vector<int> val(MAXN, 0);

void dfs(int u, int p) {
	par[u] = p;
	int mxz = 0;
	
	for (int v : g[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
			sz[u] += sz[v];
			
			if (sz[v] > mxz) {
				mxz = sz[v];
				heavy[u] = v;
			}
		}
	}
}

int ti = 0;

void decompose(int u, int h) {
	head[u] = h;
	pos[u] = ++ti;
	og[pos[u]] = val[u];
	
	if (heavy[u]) decompose(heavy[u], h);
	
	for (int v : g[u]) {
		if (v == heavy[u] || v == par[u]) continue;
		decompose(v, v);
	}
}

//ST25

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = og[l];
		return;
	}
	
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return;
	if (l == r) {
		ST[id] = val;
		return;
	}
	
	int mid = (l + r) / 2;
	update(id << 1, l, mid, pos, val);
	update(id << 1 | 1, mid + 1, r, pos, val);
	
	ST[id] = max(ST[id << 1], ST[id << 1 | 1]);
}

int query(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return -LLONG_MAX;
	if (x <= l && r <= y) {
		return ST[id];
	}
	int mid = (l + r) / 2;
	return max(query(id << 1, l, mid, x, y), query(id << 1 | 1, mid + 1, r, x, y));
}

int res(int u, int v) {
	int ans = -LLONG_MAX;
	while (head[u] != head[v]) {
		if (depth[head[u]] < depth[head[v]]) swap(u, v);
		ans = max(ans, query(1, 1, n, pos[head[u]], pos[u]));
		u = par[head[u]];
	}
	if (depth[u] > depth[v]) swap(u, v);
	return max(ans, query(1, 1, n, pos[u], pos[v]));
}

void testcase() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 1; i <= n - 1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	decompose(1, 1);
	build(1, 1, n);
	
	while (q--) {
		int u, a, b; cin >> u >> a >> b;
		if (u == 1) {
			update(1, 1, n, pos[a], b);
		}
		if (u == 2) {
			cout << res(a, b) << el;
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
