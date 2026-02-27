#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

vector<int> g[MAXN];
int dp[2][MAXN];

int res1 = 0;
int res2 = 0;

void dfs(int u, int p) {
	dp[0][u] = 0;
	dp[1][u] = 1;
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[0][u] += max(dp[1][v], dp[0][v]);
		dp[1][u] += dp[0][v];
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
	
	cout << max(dp[0][1], dp[1][1]);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
