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

struct DSU {
	vector<int> par, sz;
	
	DSU(int n) : par(n), sz(n) {
	};
	
	void make(int u) {
		par[u] = u;
		sz[u] = 1;
	}
	
	int find(int u) {
		return u == par[u] ? u : par[u] = find(par[u]);
	}
	
	void unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (sz[u] < sz[v]) swap(u, v);
		
		par[v] = u;
		sz[u] += sz[v];
	}
};

struct edge {
	int u, v;
	int w;
	int id;
};

vector<edge> edges;

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		edges.push_back({u, v, w, i});
	}
	vector<bool> ans(m + 1, 0);
	
	sort(edges.begin(), edges.end(), [](edge x, edge y) {
		return x.w < y.w;
	});
	
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	int i = 0;
	
	while (i < m) {
		int w0 = edges[i].w;
		int j = i;
		while (j < m && edges[j].w == w0) ++j;
		for (int k = i; k < j; k++) {
			auto [u, v, z, idx] = edges[k];
			if (dsu.find(u) != dsu.find(v)) ans[idx] = 1;
		}
		for (int k = i; k < j; k++) {
			auto [u, v, z, idx] = edges[k];
			dsu.unite(u, v);
		}
		i = j;
	}
	
	for (int i = 1; i <= m; i++) cout << ans[i];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
