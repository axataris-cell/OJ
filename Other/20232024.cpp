#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define FILENAME "TDL"

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
vector<int> dist(MAXN, 0), child(MAXN, 1);
bool vis[MAXN];

void dfs(int s) {
	vis[s] = true;
	for (auto v : g[s]) {
		if (!vis[v]) dfs(v);
		child[s] += child[v];
	}
}

bool comp(int u, int v) {
	return sz[u] > sz[v];
}

void testcase() {
	int n; cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end(), comp);
	int amount; cin >> amount;
	
	queue<int> q;
	
	int s, t;
	if (amount == 1) {
		cin >> s;
		q.push(s);
		vis[s] = true;
	} else {
		cin >> s >> t;
		q.push(s); q.push(t);
		vis[s] = vis[t] = true;
	}
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		int time = dist[u];
		for (auto v : g[u]) {
			if (!vis[v]) {
				dist[v] = ++time;
				vis[v] = true;
				q.push(v);
			}
		}
	}
	
	int res = -INT_MAX;
	for (int i = 1; i <= n; i++) {
		res = max(dist[i], res);
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
