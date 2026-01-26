#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define int long long

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

int n, m, k;

vector<pii> g[MAXN];
int dist[6][MAXN];

struct path {
	int u, d;
	int cnt;
};

struct comp {
	bool operator()(path &x, path &y) const {
		return x.d > y.d;
	}
};

void dijkstra(int s) {
	pqueue<path, vector<path>, comp> pq;
	
	pq.push({s, 0, 0}); 
	dist[0][s] = 0;
	
	while (pq.size()) {
		path x = pq.top(); pq.pop();
		int u = x.u;
		int d = x.d;
		
		if (d > dist[x.cnt][u]) continue; //?
		
		for (auto y : g[u]) {
			int v = y.first;
			int w = y.second;
			if (dist[x.cnt][v] > dist[x.cnt][u] + w) {
				dist[x.cnt][v] = dist[x.cnt][u] + w;
				pq.push({v, dist[x.cnt][v], x.cnt});
			}
		}
		if (x.cnt < k) {
			for (auto y : g[u]) {
				int v = y.first;
				if (dist[x.cnt + 1][v] > dist[x.cnt][u]) {
					dist[x.cnt + 1][v] = dist[x.cnt][u];
					pq.push({v, dist[x.cnt + 1][v], x.cnt + 1});
				}
			}
		}
	}
}

void testcase() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dijkstra(1);
	int res = LLONG_MAX;
	for (int i = 0; i < 6; i++) {
		res = min(res, dist[i][n]);
	}
	cout << (res == LLONG_MAX ? -1 : res);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();
	
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < MAXN; j++) {
			dist[i][j] = LLONG_MAX;
		}
	}
	
	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
