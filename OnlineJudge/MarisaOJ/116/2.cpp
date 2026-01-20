#include <bits/stdc++.h>
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
vector<int> g[MAXN];
vector<int> dist(MAXN, -1);
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= n; i++) {
		cout << dist[i] << ' ';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
