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
		return (u == par[u] ? u : par[u] = find(par[u]));
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
	
	int avail(int u) {
		return sz[find(u)];
	}
};

const int MAXN = 1e5 + 5;

bool vis[MAXN];

void testcase() {
	int n, m; cin >> n >> m;
	int q; cin >> q;
	
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	vector<pii> edges(m + 1);
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		edges[i] = {a, b};
	}
	
	vector<pii> truyvan(q + 1);
	for (int i = 1; i <= q; i++) {
		int e, c; cin >> e >> c;
		vis[e] = true;
		truyvan[i] = {e, c};
	}
	for (int i = 1; i <= m; i++) {
		if (!vis[i]) dsu.unite(edges[i].first, edges[i].second);
	}
//	cerr << "DEBUG" << dsu.avail(1) << ' ' << dsu.avail(2) << el;
//	cerr << "DEBUG" << dsu.avail(3) << ' ' << dsu.avail(4) << el;
	
	vector<int> res;
	for (int i = q; i >= 1; i--) {
		res.push_back(dsu.avail(truyvan[i].second));
		int j = truyvan[i].first;
		dsu.unite(edges[j].first, edges[j].second);
//		cerr << "EDGE: " << edges[j].first << ' ' << edges[j].second << el;
//		cerr << "DEBUG: ";
//		for (int i = 1; i <= n; i++) cerr << dsu.avail(i) << ' ';
//		cerr << el;
	}

	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
