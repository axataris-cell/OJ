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

vector<int> g[MAXN], deg(MAXN, 0), topo;
vector<set<int>> adj(MAXN);

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int k, a, b;
		cin >> k >> a >> b;
		if (k == 1) {
			g[a].push_back(b);
			++deg[b];
		} else if (k == 0) {
			adj[a].insert(b);
			adj[b].insert(a);
		}
	}
	
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		topo.push_back(u);
		for (int v : g[u]) {
			if (--deg[v] == 0) q.push(v);
		}
		for (int v : adj[u]) {
			g[u].push_back(v);
			adj[v].erase(u);
		}
	}
	
	if (topo.size() < n) {
		cout << "NO";
	} else {
		cout << "YES" << el;
		for (int i = 1; i <= n; i++) {
			for (auto u : g[i]) {
				cout << i << ' ' << u << el;
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
