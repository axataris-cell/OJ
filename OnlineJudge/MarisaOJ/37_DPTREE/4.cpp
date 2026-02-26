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

int n, k;
int dp[105][MAXN];

vector<int> g[MAXN];
int res = 0;

void dfs(int u, int p)
{
	for (int v : g[u]) {
		if (v == p) continue;
		dfs(v, u);
		
		for (int i = 0; i < k; i++) {
			res += dp[i][u] * dp[k - i - 1][v];
		}
		for (int i = 1; i <= k; i++) {
			dp[i][u] += dp[i - 1][v];
		}
	}
}

void testcase() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) dp[0][i] = 1;
	dfs(1, 1);
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
