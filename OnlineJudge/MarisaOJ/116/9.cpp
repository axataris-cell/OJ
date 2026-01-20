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
vector<int> g[MAXN];
vector<int> dist(MAXN, 0);
bool vis[MAXN];

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		
		for (auto v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	
	int k; cin >> k;
	vector<int> call(k);
	for (int i = 0; i < k; i++) cin >> call[i];
	
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	bfs(n);
	
	for (int i = 0; i < k; i++) {
		cout << dist[call[i]] << ' ';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
