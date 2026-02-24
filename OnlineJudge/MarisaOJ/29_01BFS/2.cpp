#include <bits/stdc++.h>
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

/*
8 12
1 4 5
1 2 2
4 2 3
4 3 4
2 3 6
3 5 9
2 5 7
5 6 1
5 8 5
5 7 2
6 8 1
7 8 1
1 8
*/

const int MAXN = 1e5 + 5;

vector<pii> g[MAXN];
vector<int> dist(MAXN, INF);

void dijkstra(int s, int t) {
	pqueue<pii, vector<pii>, greater<pii>> pq;
	
	pq.push({0, s});
	dist[s] = 0;
	
	while (pq.size()) {
		pii x = pq.top(); pq.pop();
		int u = x.second;
		int d = x.first;
		
		if (d > dist[u]) continue;
		
		for (pii y : g[u]) {
			int v = y.first;
			int w = y.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	
	int s, t; cin >> s >> t;
	
	dijkstra(s, t);
	
	if (dist[t] == INF) cout << -1;
	else cout << dist[t];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
