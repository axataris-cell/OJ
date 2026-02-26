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

#define int long long

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
vector<int> val(MAXN, 0);
vector<int> dp(MAXN, -LINF);

int res = -LINF;

void dfs(int u, int p) {
    dp[u] = val[u];
    int best1 = -LINF;
    int best2 = -LINF;

    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u);

        if (dp[v] > best1) {
            best2 = best1;
            best1 = dp[v];
        } else if (dp[v] > best2) {
            best2 = dp[v];
        }
    }

    if (best1 != -LINF) {
        dp[u] = max(dp[u], val[u] + best1);
    }

    if (best2 != -LINF) {
        res = max(res, val[u] + best1 + best2);
    }

    res = max(res, dp[u]);
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
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
