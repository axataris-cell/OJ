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

//67 Decomposition

const int MAXN 2e5 + 5;

vector<int> g[MAXN];
vector<int> sz(MAXN, 0)
vector<int> h(MAXN, 0), head(MAXN, 0), heavy(MAXN, 0);

void dfs(int u, int p) {
	int best = 0;
	for (int v : g[u]) {
		if (v == p) continue;
		h[v] = h[u] + 1;
		dfs(v, u);
		if (best < sz[v]) {
			best = sz[v];
			heavy[u] = v;
		}
	}
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 1);
	decompose(1, 1);
	
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
