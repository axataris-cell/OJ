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
	vector<int>	 color, par;
	
	DSU(int n) : color(n), par(n) {}
	
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
	
	void unite(int u, int v) {
		int pu = find(u);
		int pv = find(v);
		if (pu == pv) return;
		par[pv] = pu;
		color[pv] = color[u] ^ color[v] ^ 1;
	}
};

const int MAXN = 1e5 + 5;

bool vis[MAXN];

void testcase() {
	int n, q; cin >> n >> q;
	
	DSU dsu(n + 1);
	for (int i = 1; i <= n; i++) dsu.make(i);
	
	while (q--) {
		int t, u, v; cin >> t >> u >> v;
		if (t == 1) {
			dsu.unite(u, v);
		} else if (t == 2) {
			int pu = dsu.find(u);
			int pv = dsu.find(v);
			
			if (pu != pv) cout << "DUNNO" << el;
			else {
				if (dsu.color[u] ^ dsu.color[v]) cout << "FATAL";
				else cout << "SAFE";
				cout << el;
			}
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
