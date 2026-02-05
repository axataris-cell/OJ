#include <bits/stdc++.h>
#include <chrono>

#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 1e9
#define LINF 1e18

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

vector<int> g[MAXN], dist(MAXN, -1), nex(MAXN, INT_MAX);
vector<vector<int>> par(MAXN, vector<int>());
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) {
			if (!vis[v] || dist[v] == dist[u] + 1) {
				if (!vis[v]) q.push(v);
				
				vis[v] = true;
				dist[v] = dist[u] + 1;
				par[v].push_back(u);
			}
		}
	}
}

void bfs2(int s) {
	queue<int> q;
	
	q.push(s);
	
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : par[u]) {
			nex[v] = min(nex[v], u);
			q.push(v);
		}
	}
}

void testcase() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(s);
	bfs2(t);
	
	for (int i = 1; i <= n; i++) {
		cout << nex[i] << ' ';
	}
	cout << el;
	
	int cur = s;
	while (cur != INT_MAX) {
		cout << cur << ' ';
		cur = nex[cur];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
