#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define int long long

using namespace std;
using pii = pair<long long, long long>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 2e5 + 5;

vector<pii> g[MAXN]; // Node - Weight
vector<int> par(MAXN, -1), dist(MAXN, LLONG_MAX);

void dijkstra(int s) {
	pqueue<pii, vector<pii>, greater<pii>> pq;
	
	dist[s] = 0;
	pq.emplace(0, s);
	
	while (!pq.empty()) {
		pii t = pq.top(); pq.pop();
		int d = t.first;
		int u = t.second;
		
		if (d > dist[u]) continue;
		
		for (auto x : g[u]) {
			int v = x.first;
			int w = x.second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				par[v] = u;
				pq.emplace(dist[v], v);
			}
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	dijkstra(1);
	
	if (dist[n] == LLONG_MAX) {
		cout << -1;
		return;
	}
	
	cout << dist[n] << el;
	
	vector<int> list; int truy = n;
	while (truy != -1) {
		list.push_back(truy);
		truy = par[truy];
	}
	reverse(list.begin(), list.end());
	
	for (auto x : list) cout << x << ' ';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}