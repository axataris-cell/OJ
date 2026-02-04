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
const int LOG = 17;

int n;

vector<int> g[MAXN], h(MAXN, 0);
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, -1));
bool vis[MAXN];

void dfs(int u, int p) {
	par[0][u] = p;
	vis[u] = true;
	for (auto v : g[u]) {
		if (!vis[v]) {
			h[v] = h[u] + 1;
			dfs(v, u);
		}
	}
}

void preprocess() {
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			if (par[i - 1][j] != -1) par[i][j] = par[i - 1][par[i - 1][j]];
			else par[i][j] = -1;
		}
	}
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	int k = h[u] - h[v];
	for (int i = 0; (1 << i) <= k; i++) {
		if (k >> i & 1) u = par[i][u];
	}
	if (u == v) return u;
	
	for (int i = LOG; i >= 0; i--) {
		if (par[i][u] != -1 && par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}

void testcase() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	preprocess();
	for (int i = 0; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			cout << par[i][j] << ' ';
		}
		cout << el;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			cout << "LCA of: " << i << ' ' << j << " = " << lca(i, j) << el;
		}
		cout << el;
	}
}
/*
33
1 2
1 3
2 4
2 5
3 6
3 7
3 8
4 9
4 10
6 11
6 12
11 13
11 14
12 15
12 16
13 17
13 18
15 19
15 20
20 21
20 22
20 23
21 24
21 25
23 26
23 27
24 28
24 29
29 30
30 31
30 32
30 33
*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
