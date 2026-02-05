#include <bits/stdc++.h>
#include <chrono>

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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
int countcmp = 0;
vector<int> comp(MAXN, 0);
bool vis[MAXN];

void bfs(int s) {
	++countcmp;
	
	queue<int> q;
	q.push(s);
	vis[s] = true;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		comp[u] = countcmp;
		for (int v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

void testcase() {
	int n; cin >> n;
	int m; cin >> m;
	
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) bfs(i);
	}
	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		if (comp[u] == comp[v]) cout << "YES";
		else cout << "NO";
		cout << el;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
