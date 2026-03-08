#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

#define FILENAME "BAI4"

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

string dir;
umap<int, umap<int, int>> g;

bool vis[MAXN];
vector<int> dist(MAXN, 0);
vector<int> adj[MAXN];


umap<char, int> dx;
umap<char, int> dy;

int mx[4] = {1, -1, 0, 0};
int my[4] = {0, 0, 1, -1};

void bfs(int s) {
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		
		for (int v : adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				
				q.push(v);
			}
		}
	}
}

void testcase() {
	dx['D'] = 1;
	dx['T'] = -1;
	dx['N'] = 0;
	dx['B'] = 0;
	
	dy['D'] = 0;
	dy['T'] = 0;
	dy['N'] = -1;
	dy['B'] = 1;

	cin >> dir;
	int x = 1;
	int y = 1;
	g[x][y] = 1;
	int mie = 1;
	for (int i = 0; i < dir.length(); i++) {
		int nx = x + dx[dir[i]];
		int ny = y + dy[dir[i]];
		if (!g[nx][ny]) g[nx][ny] = ++mie;
		int u = g[x][y];
		int v = g[nx][ny];
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		
		x = nx;
		y = ny;
	}
	
	bfs(1);
	
	cout << dist[g[x][y]];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
