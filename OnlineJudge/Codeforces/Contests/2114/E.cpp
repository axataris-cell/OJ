#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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

const int MAXN = 2e5 + 5;
vector<int> g[MAXN];
vector<int> dp1(MAXN, -LINF), dp2(MAXN, LINF);
vector<int> a(MAXN + 1, 0);
// luu dp1[i] = max threat, dp2[i] = min threat;

void dfs(int u, int p) {
	for (int v : g[u]) {
		if (v == p) continue;
		dp1[v] = max(a[v] - dp2[u], a[v]);
		dp2[v] = min(a[v] - dp1[u], a[v]);
		dfs(v, u);
	}
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		g[i].clear();
		dp1[i] = -LINF;
		dp2[i] = LINF;
	}
	
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dp1[1] = a[1];
	dp2[1] = a[1];
	
	dfs(1, 1);
	
	for (int i = 1; i <= n; i++) cout << dp1[i] << ' ';
	cout << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
