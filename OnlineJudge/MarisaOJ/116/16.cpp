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

void debug_time(const string& label = "") {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(now - start).count();
    cerr << "[TIME] " << label << ": " << ms << " ms\n";
}

const int MAXN = 1e5 + 5;
vector<pii> g[MAXN];
vector<int> dist(MAXN, -1), tiep(MAXN, INT_MAX), path, nex(MAXN, -1);
vector<vector<int>> par(MAXN, vector<int>());
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		for (pii x : g[u]) {
			int v = x.first;
			int w = x.second;
			if (!vis[v] || dist[v] == dist[u] + 1) {
				if (!vis[v]) q.push(v);
				
				vis[v] = true;
				dist[v] = dist[u] + 1;
				par[v].push_back(u);
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
	bfs(1);
	cout << dist[n] << el;
	
//	for (int i = 1; i <= n; i++) {
//		cerr << "Parent of " << i << ": ";
//		for (auto x : par[i]) cerr << x << ' ';
//		cerr << el;
//	}

	queue<int> q;
	q.push(n);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : par[u]) {
			int w;
			for (pii x : g[u]) if (x.first == v) {
				w = x.second;
				break;
			}
			if (tiep[v] > w) {
				tiep[v] = w;
				nex[v] = u;
			}
			q.push(v);
		}
	}
//	
//	for (int i = 1; i <= n; i++) {
//		cerr << tiep[i] << ' ' << nex[i] << el;
//	}
//	
//	cerr << "Answer" << el;
	int cur = 1;
	while (cur != n) {
		cout << tiep[cur] << ' ';
		cur = nex[cur];
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	//debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
