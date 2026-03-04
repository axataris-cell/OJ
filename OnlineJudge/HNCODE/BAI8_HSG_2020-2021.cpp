#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

#define FILENAME "BTS"

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

int n;

struct DSU {
	vector<int> sz, par;
	
	DSU(int n) : sz(n), par(n) {};
	
	void make(int u) {
		par[u] = u;
		sz[u] = 1;
	}
	
	int find(int u) {
		return ((u == par[u]) ? u : par[u] = find(par[u]));
	}
	
	bool join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		if (sz[u] < sz[v]) swap(u, v);
		sz[u] += sz[v];
		par[v] = u;
		return true;
	}
};

struct dat{
	int x, y;
	int idx;
};

struct edge {
	int dist;
	int x, y;
};

vector<dat> coord; // val

void testcase() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		coord.push_back({x, y, i});
	}
	
	DSU dsu(n);
	for (int i = 0; i < n; i++) dsu.make(i);
	
	ll res = 0;
	vector<edge> edges;
	
	sort(coord.begin(), coord.end(), [](dat x, dat y) {
		return x.x < y.x;
	});
	
	for (int i = 0; i < n - 1; i++) {
		edges.push_back({min(abs(coord[i].x - coord[i + 1].x), abs(coord[i].y - coord[i + 1].y)), coord[i].idx, coord[i + 1].idx});
	}
	
	sort(coord.begin(), coord.end(), [](dat x, dat y) {
		return x.y < y.y;
	});
	
	for (int i = 0; i < n - 1; i++) {
		edges.push_back({min(abs(coord[i].x - coord[i + 1].x), abs(coord[i].y - coord[i + 1].y)), coord[i].idx, coord[i + 1].idx});
	}
	
	sort(edges.begin(), edges.end(), [](edge x, edge y) {
		return x.dist < y.dist;
	});
	
	for (auto e : edges) {
		if (dsu.join(e.x, e.y)) {
			res += e.dist;
		}
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
