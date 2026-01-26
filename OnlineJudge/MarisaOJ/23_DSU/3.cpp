#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define int long long
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

struct DSU {
	vector<int> sz, par;
	
	DSU(int n) : sz(n), par(n) {};
	
	void make(int u) {
		sz[u] = 1;
		par[u] = u;
	}
	
	int find(int u) {
		return (par[u] == u ? u : par[u] = find(par[u]));
	}
	
	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		if (u != v) {
			if (sz[u] < sz[v]) swap(u, v);
			par[v] = u;
			sz[u] += sz[v];
		}
		return true;
	}
};

struct edge {
	int u, v;
	int d;
};

vector<edge> edges;

void testcase() {
	int n, m; cin >> n >> m;
	
	DSU dsu(n + 5);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}
	sort(edges.begin(), edges.end(), [](edge &x, edge &y) {
		return x.d < y.d;
	});
	int res = 0;
	for (edge x : edges) {
		if (!dsu.unite(x.u, x.v)) continue;
		res += x.d;
	}
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
