vector<int> g[MAXN];
bool vis[MAXN];

void dfs(int s) {
	vis[s] = true;
	
	for (int v : g[s]) {
		if (!vis[v]) dfs(v);
	}
}