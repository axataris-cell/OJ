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

int n, m;

vector<int> g[MAXN], topo, deg(MAXN, 0);
bool vis[MAXN];

void bfs() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg1[i] == 0) {
			q.push(i);
			vis[i] = true;
		}
	}
	while (q.size()) {
		int u = q.front(); q.pop();
		topo.push_back(u);
		for (int v : g[u]) {
			if (!vis[v]) {
				--deg1[v];
				if (deg1[v] == 0) q.push(v);
			}
		}
	}
}

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		++deg[b];
	}
	bfs();
	if (topo.size() < n) cout << "NO";
	else cout << "YES";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
