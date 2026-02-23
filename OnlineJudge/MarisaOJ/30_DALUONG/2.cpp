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
#define int long long
#define INF 4e18

const int MAXN = 2e5 + 5;

vector<int> color(MAXN, 0);
vector<pll> g[MAXN];
int dist[51][MAXN];


void testcase() {
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}
	for (int i = 1; i <= m; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	
	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
	
	for (int i = 1; i <= k; i++) {
		pqueue<pll, vector<pll>, greater<pll>> pq; //w - n
		
		for (int u = 1; u <= n; u++) {
			if (color[u] == i) {
				dist[i][u] = 0;
				pq.push({0, u});
			}
		}
		
		while (pq.size()) {
			pll x = pq.top(); pq.pop();
			int d = x.first;
			int u = x.second;
			
			if (d > dist[i][u]) continue;
			
			for (pll y : g[u]) {
				int w = y.second;
				int v = y.first;
				if (dist[i][v] > dist[i][u] + w) {
					dist[i][v] = dist[i][u] + w;
					pq.emplace(dist[i][v], v);
				}
			}
		}
	}
	
	int bestNode = -1;
	int bestDist = INF;
	for (int i = 1; i <= n; i++) {
		ll total = 0;
		
		bool ok = true;
		for (int j = 1; j <= k; j++) {
			if (dist[j][i] == INF) {
				ok = false;
				break;
			}
			total += dist[j][i] * 1LL;
		}
		if (!ok) continue;
		
		if (total < bestDist) {
			bestDist = total;
			bestNode = i;
		}
	}
	
	cout << bestNode;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
