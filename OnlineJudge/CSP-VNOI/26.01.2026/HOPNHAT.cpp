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
	vector<int> par, sz;
	
	DSU(int n) : par(n), sz(n) {};
	
	void make(int u) {
		par[u] = u;
		sz[u] = 1;
	}
	
	int find(int u) {
		return u == par[u] ? u : par[u] = find(par[u]);
	}
	
	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		else {
			if (sz[u] < sz[v]) swap(u, v);
			par[v] = u;
			sz[u] += sz[v];
			return true;
		}
	}
};

void testcase() {
	int n, m; cin >> n >> m;
	
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	while (m--) {
		int u, v; cin >> u >> v;
		if (dsu.unite(u, v)) {
			cout << "Y" << el;
		} else {
			cout << "N" << el;
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
