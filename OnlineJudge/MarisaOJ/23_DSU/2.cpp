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

struct DSU {
	vector<int> sz, par, sum;
	
	DSU(int n) : sz(n), par(n), sum(n) {};
	
	void make(int u) {
		sz[u] = 1;
		par[u] = u;
		sum[u] = u;
	}
	
	int find(int u) {
		return (par[u] == u ? u : par[u] = find(par[u]));
	}
	
	void unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v) {
			if (sz[u] < sz[v]) swap(u, v);
			par[v] = u;
			sz[u] += sz[v];
			sum[u] += sum[v];
		}
	}
};
void testcase() {
	int n, q; cin >> n >> q;
	
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	while (q--) {
		int x; cin >> x;
		if (x == 1) {
			int u, v; cin >> u >> v;
			dsu.unite(u, v);
		} else if (x == 2) {
			int u; cin >> u;
			cout << dsu.sum[dsu.find(u)] << el;
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
