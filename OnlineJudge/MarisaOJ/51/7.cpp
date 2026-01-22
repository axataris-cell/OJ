#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define int long long
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

void debug_time(const string& label = "") {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(now - start).count();
    cerr << "[TIME] " << label << ": " << ms << " ms\n";
}

const int MAXN = 1e5 + 5;
vector<pii> g[MAXN];
vector<int> dist(MAXN, LLONG_MAX), par(MAXN, -1);

void dijkstra(int s) {
	pqueue<pii, vector<pii>, greater<pii>> pq; // weight first
	
	pq.emplace(0, s);
	dist[s] = 0;
	
	while (pq.size()) {
		auto x = pq.top(); pq.pop();
		int d = x.first, u = x.second;
		
		if (d > dist[u]) continue;
		
		for (auto y : g[u]) {
			int v = y.first;
			int w = y.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				par[v] = u;
				pq.emplace(dist[v], v);
			}
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	int s, t, x, y;
	cin >> s >> t >> x >> y;
	for (int i = 1; i <= m; i++) {
		int a, b, w; cin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	dijkstra(s);
	
	vector<int> path;
	int k = t;
	while (k != -1) {
		path.push_back(k);
		k = par[k];
	}
	reverse(path.begin(), path.end());
	
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
