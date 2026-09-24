#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
vector<int> g[MAXN];
int depth[MAXN], up[MAXN], down[MAXN];
int dp[2][MAXN];
void dfs(int u, int p) {
	for (int v : g[u]) if (v != p) {
		depth[v] = depth[u] + 1;
		dfs(v, u);
		down[u] = max(down[v] + 1, down[u]);
		if (dp[0][v] + 1 > dp[0][u]) {
			dp[1][u] = dp[0][u];
			dp[0][u] = dp[0][v] + 1;
		} else if (dp[0][v] + 1 > dp[1][u]) {
			dp[1][u] = dp[0][v] + 1;
		}
	}
}
void dfs2(int u, int p, bool unique) {
	if (u != p) {
		if (unique) up[u] = max(up[p] + 1, dp[1][p] + 1);
		else up[u] = max(up[p] + 1, dp[0][p] + 1);
	}
	int cntBest = 0;
	for(int v : g[u]) if (v != p) {
		if (dp[0][v] + 1 == dp[0][u]) ++cntBest;
	}
	for (int v : g[u]) if (v != p) {
		if (dp[0][v] + 1 == dp[0][u] && cntBest < 2) dfs2(v, u, true);
		else dfs2(v, u, false);
	}
}
void testcase() {
	int n, k, c; cin >> n >> k >> c;
	for(int i = 1; i <= n; i++){
		g[i].clear();
		depth[i] = 0;
		up[i] = 0;
		down[i] = 0;
		dp[0][i] = dp[1][i] = 0;
	}
	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 1);
	dfs2(1, 1, false);
	int res = down[1] * k;
	for(int i = 1; i <= n; i++) {
		res = max(res, up[i] * k - depth[i] * c);
	}
	cout << res << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

