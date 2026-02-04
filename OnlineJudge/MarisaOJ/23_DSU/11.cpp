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
	vector<int> par, color;
	
	DSU(int n) : par(n), color(n) {};
	
	void make(int u) {
		par[u] = u;
		color[u] = 0;
	}
	
	int find(int u) {
		if (u == par[u]) return u;
		
		int pu = par[u];
		int r = find(pu);
		
		color[u] ^= color[pu];
		
		return par[u] = r;
	}
	
	bool unite(int u, int v, int w) {
		int pu = find(u);
		int pv = find(v);

	    if (pu == pv) {
	        return (color[u] ^ color[v]) == w;
	    }
	    
		par[pv] = pu;
		color[pv] = color[u] ^ color[v] ^ w;
		return true;
	}
};

void testcase() {
	int n, q; cin >> n >> q;
	int cnt = 0;
	
	DSU dsu(n + 1);
	for (int i = 0; i <= n; i++) dsu.make(i);
	
	while (q--) {
		int l, r, t; cin >> l >> r >> t;
		if (!dsu.unite(r, l - 1, t)) break;
		++cnt;
	}
	
	cout << cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
