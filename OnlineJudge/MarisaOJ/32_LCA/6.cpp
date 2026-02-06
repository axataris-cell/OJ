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
const int LOG = 18;

int n, q;

vector<int> g[MAXN], h(MAXN, 0);
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
bool vis[MAXN];

void dfs(int s) {
	vis[s] = true;
	for (int v : g[s]) {
		if (!vis[v]) {
			par[0][v] = s;
			h[v] = h[s] + 1;
			dfs(v);
		}
	}
}

void preprocess() {
	dfs(1);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	if (h[u] != h[v]) {
		int diff = h[u] - h[v];
		for (int i = 0; i <= LOG; i++) {
			if (diff >> i & 1) {
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

int res(int u, int v, int w) {
	if (u < v) swap(u, v);
	if (v < w) swap(v, w);
	if (u < v) swap(u, v);
	// h[u] >= h[v] >= h[w]
	vector<pii> posi;
	int a1 = lca(u, v);
	int a2 = lca(v, w);
	int a3 = lca(u, w);
	posi.push_back({h[u] + h[v] + h[w] - h[a1] - 2 * h[lca(a1, w)], a1});
	posi.push_back({h[u] + h[v] + h[w] - h[a2] - 2 * h[lca(a2, w)], a2});
	posi.push_back({h[u] + h[v] + h[w] - h[a3] - 2 * h[lca(a3, w)], a3});
	
	sort(posi.begin(), posi.end());
	
	return posi[0].second;
}

void testcase() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	preprocess();
	while (q--) {
		int u, v, w; cin >> u >> v >> w;
		cout << res(u, v, w) << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
