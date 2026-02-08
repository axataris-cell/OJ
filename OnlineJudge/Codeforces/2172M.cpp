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

const int MAXN = 2e5 + 5;

vector<int> types(MAXN, 0);
vector<int> g[MAXN], dist(MAXN, -1);
vector<int> res(MAXN, 0); // theo k
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		res[types[u]] = max(dist[u], res[types[u]]);
		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

void testcase() {
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> types[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(1);
	for (int i = 1; i <= k; i++) {
		cout << res[i] << ' ';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
