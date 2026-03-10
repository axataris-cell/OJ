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

struct DSU {
	vector<int> sz, par, mn, mx;
	
	DSU (int n) : sz(n), par(n), mn(n), mx(n) {};
	
	void make(int u) {
		par[u] = u;
		sz[u] = 1;
		mn[u] = INF;
		mx[u] = -INF;
	}
	
	int find(int u) {
		return par[u] == u ? u : par[u] = find(par[u]);
	}
	
	void join(int u, int v, int w) {
		u = find(u);
		v = find(v);
		if (u == v) {
			mn[u] = min(mn[u], w);
			mx[u] = max(mx[u], w);
			return;
		}
		if (sz[u] < sz[v]) swap(u, v);
		mn[u] = min({mn[u], mn[v], w});
		mx[u] = max({mx[u], mx[v], w});
		par[v] = u;
		sz[u] += sz[v];
	}
};

struct edge {
	int u, v, w;
};

/*
1
6 5
4 5 17
1 6 15
1 3 17
2 5 13
3 4 10
*/

void testcase() {
	int n, m; cin >> n >> m;
	vector<pii> g[n + 1];
	vector<edge> edges;
	for (int i = 1; i <= m; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
		edges.push_back({a, b, w});
	}
	
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	sort(edges.begin(), edges.end(), [](edge x, edge y) {
		return x.w < y.w;
	});
	
//	int mn = INF;
//	int mx = -INF;
	
	int res = INF;
	
	for (auto e : edges) {
		int u = dsu.find(e.u);
		int v = dsu.find(e.v);
//		dsu.mn[u] = min(dsu.mn[u], e.w);
//		dsu.mx[u] = max(dsu.mx[u], e.w);
//		dsu.mn[v] = min(dsu.mn[v], e.w);
//		dsu.mx[v] = max(dsu.mx[v], e.w);
		dsu.join(e.u, e.v, e.w);
//		cerr << e.u << ' ' << e.v << ' ' << e.w << el;
		int find1 = dsu.find(1);
		int findn = dsu.find(n);
		if (find1 == findn) {
			res = min(res, dsu.mn[find1] + dsu.mx[find1]);
		}
	}
	int group = dsu.find(1);
	cout << res << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
