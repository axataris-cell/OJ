#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

int n, m;

vector<int> g[MAXN];
vector<int> sz(MAXN, 1), heavy(MAXN, -1), par(MAXN, 0);
vector<int> h(MAXN, 0), pos(MAXN, 0), val(MAXN, 0);
vector<int> head(MAXN, 0);
vector<int> a(MAXN, 0);
vector<int> ST(MAXN, 0), lz(MAXN, 0);

void dfs(int u, int p) {
	int best = 0;
	for (int v : g[u]) {
		if (v == p) continue;
		par[v] = u;
		h[v] = h[u] + 1;
		dfs(v, u);
		sz[u] += sz[v];
		if (sz[v] > best) {
			heavy[u] = v;
			best = sz[v];
		}
	}
}

int timeDfs = 0;

void decompose(int u, int h) {
	pos[u] = ++timeDfs;
	a[timeDfs] = val[u];
	head[u] = h;
		
	if (heavy[u] != -1) decompose(heavy[u], h);
	
	for (int v : g[u]) {
		if (v == par[u] || v == heavy[u]) continue;
		decompose(v, v);
	}
}

void buildST(int id, int l, int r) {
	if (l == r) {
		ST[id] = a[l];
		return;
	}
	
	int mid = (l + r) / 2;
	buildST(id << 1, l, mid);
	buildST(id << 1 | 1, mid + 1, r);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void push(int id, int l, int r) {
	if (lz[id] == 0) return;
	
	int mid = (l + r) / 2;
	
	ST[id << 1] += (mid - l + 1) * lz[id];
	lz[id << 1] += lz[id];
	
	ST[id << 1 | 1] += (r - mid) * lz[id];
	lz[id << 1 | 1] += lz[id];
	
	lz[id] = 0;
}

int queryST(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return 0;
	if (x <= l && r <= y) {
		return ST[id];
	}
	
	push(id, l, r);
	
	int mid = (l + r) / 2;
	return queryST(id << 1, l, mid, x, y) + queryST(id << 1 | 1, mid + 1, r, x, y);
}

void updateST(int id, int l, int r, int x, int y, int val) {
	if (l > y || r < x) return;
	if (x <= l && r <= y) {
		ST[id] = (r - l + 1) * val;
		lz[id] += val;
		return;
	}
	
	int mid = (l + r) / 2;
	
	updateST(id << 1, l, mid, x, y, val);
	updateST(id << 1 | 1, mid + 1, r, x, y, val);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void update(int u, int v, int val) {
	
}

int query(int u, int v) {
	int res = 0;
	while (head[u] != head[v]) {
		if (pos[u] > pos[v]) swap(u, v);
	}
}

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	decompose(1, 1);
	buildST(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int t, u, v; cin >> t >> u >> v;
		if (t == 1) {
			int val; cin >> val;
			update(u, v, val);
		} else if (t == 2) {
			cout << query(u, v) << el;
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
