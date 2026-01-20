#include <bits/stdc++.h>
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

const int MAXN = 1e5 + 5;
vector<int> g[MAXN], color(MAXN, 0);
bool vis[MAXN], res = true;

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	color[s] = 0;
	
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		for (auto v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				color[v] = 1 - color[u];
				q.push(v);
			} else {
				if (color[v] == color[u]) {
					res = false;
					break;
				}
			}
		}
		if (!res) break;
	}
}

void testcase() {
	int n, m ; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) bfs(i);
	}
	cout << (res ? "YES" : "NO");
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
