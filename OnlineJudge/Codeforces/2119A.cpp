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

int a, b, x, y;

void dijkstra(int s, vector<int> &dist) {
	pqueue<pii, vector<pii>, greater<pii>> pq;
	
	pq.emplace(0, s);
	dist[s] = 0;
	
	while (pq.size()) {
		pii k = pq.top(); pq.pop();
		int d = k.first, u = k.second;
		
		if (d > dist[u]) continue;
		
		if (dist[u ^ 1] > dist[u] + y && u ^ 1 >= 1 && u ^ 1 <= 100) {
			dist[u ^ 1] = dist[u] + y;
			pq.emplace(dist[u ^ 1], u ^ 1);
		}
		
		if (dist[u + 1] > dist[u] + x && u + 1 >= 1 && u + 1 <= 100) {
			dist[u + 1] = dist[u] + x;
			pq.emplace(dist[u + 1], u + 1);
		}
	}
}

void testcase() {
	cin >> a >> b >> x >> y;
	vector<int> dist(101, INT_MAX);
	dijkstra(a, dist);
	if (dist[b] != INT_MAX) cout << dist[b] << el;
	else cout << -1 << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
