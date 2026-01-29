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

const int MAXN = 1e5 + 5;

int n, m, k;

vector<int> g[MAXN];
vector<vector<int>> dist(11, vector<int>(MAXN, -1));
bool vis[11][MAXN];

void bfs() {
	queue<pii> q;
	
	q.emplace(1, 0);
	dist[0][1] = 0;
	vis[0][1] = true;
	
	while (q.size()) {
		pii x = q.front(); q.pop();
		int u = x.first, cruk = x.second;
		for (auto v : g[u]) {
			if (!vis[(cruk + 1) % k][v]) {
				q.emplace(v, (cruk + 1) % k);
				vis[(cruk + 1) % k][v] = true;
				dist[(cruk + 1) % k][v] = dist[cruk][u] + 1;
			}
		}
	}
}

void testcase() {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs();
	if (dist[0][n] != -1) cout << dist[0][n] / k;
	else cout << -1;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
