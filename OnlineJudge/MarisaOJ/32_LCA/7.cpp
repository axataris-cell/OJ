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

#define int long long

const int MAXN = 1e5 + 5;
const int LOG = 19;

int n, q;

vector<int> g[MAXN], h(MAXN, 0), d(MAXN, 0);
vector<vector<int>> par(LOG + 1, vector<int>(MAXN, 1));
bool vis[MAXN];

void dfs(int u) {
	vis[u] = true;
	for (int v : g[u]) {
		if (!vis[v]) {
			h[v] = h[u] + 1;
			par[0][v] = u;
			dfs(v);
		}
	}
}

void preprocess() {
	dfs(1);
	for (int i = 1; i <= LOG; i++) {
		for (int u = 1; u <= n; u++) {
			par[i][u] = par[i - 1][par[i - 1][u]];
		}
	}
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	if (h[u] != h[v]) {
		int k = h[u] - h[v];
		for (int i = 0; i <= LOG; i++) {
			if (k >> i & 1) {
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

void update(int u, int v, int w) {
    int anc = lca(u, v);
    d[u] += w;
    d[v] += w;
    d[anc] -= w;
    if (par[0][anc] != anc) d[par[0][anc]] -= w;
}

void build(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;
        build(v, u);
        d[u] += d[v];
    }
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
		int u, v, w;
		cin >> u >> v >> w;
		update(u, v, w);
	}
	build(1, 1);
	for (int i = 1; i <= n; i++) cout << d[i] << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
