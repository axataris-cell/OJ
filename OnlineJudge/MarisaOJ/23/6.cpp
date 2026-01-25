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
	vector<int> sz, par;
	
	DSU(int n) : sz(n), par(n) {};
	
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
		if (u != v) {
			if (sz[u] < sz[v]) swap(u, v);
			par[v] = u;
			sz[u] += sz[v];
		}
	}
	
	int size(int u) {
		return sz[find(u)];;
	}
};

void testcase() {
	int n; cin >> n;
	int q; cin >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<pii> query(q);
	for (int i = 0; i < q; i++) {
		cin >> query[i].first;
		query[i].second = i;
	}
	
	sort(query.begin(), query.end());
	
	vector<int> ord(n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int x, int y) {
		return a[x] < a[y];
	});
	
	DSU dsu(n);
	for (int i = 0; i < n; i++) dsu.make(i);
	
	vector<int> res(q);
	vector<bool> vis(n, false);
	
	int ptr = 0;
	int best = 0;
	
	for (auto [k, id] : query) {
		while (ptr < n && a[ord[ptr]] <= k) {
			int u = ord[ptr];
			vis[u] = true;
			
			if (u > 0 && vis[u - 1]) dsu.unite(u, u - 1);
			if (u + 1 < n && vis[u + 1]) dsu.unite(u, u + 1);
			
			best = max(best, dsu.size(u));	
			
			++ptr;
		}
		res[id] = best;
	}
	
	for (int i = 0; i < q; i++) {
		cout << res[i] << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
