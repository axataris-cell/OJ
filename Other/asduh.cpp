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

const int MAXN = 1e5 + 5;
const int LOG = 40;

int n;

vector<int> g[MAXN], depth(MAXN, 0);
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));

void dfs(int u, int p) {
	par[0][u] = p;
	for (int v : g[u]) {
		if (v == p) continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}
}

void preprocess() {
	dfs(1, 1);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) swap(u, v);
	if (depth[u] != depth[v]) {
		int diff = depth[u] - depth[v];
		for (int i = 0; i <= LOG; i++) {
			if ((diff >> i) & 1) {
				u = par[i][u];
			}
		}
	}
	
	if (u == v) return u;
	
	for (int i = LOG; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	
	return par[0][u];
}

void testcase() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	preprocess();

	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << lca(a, b) << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
