#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

const int MAXN = 1005;

int n, m;
pii s, t;

int g[MAXN][MAXN];
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool visNum[MAXN * MAXN];
vector<pii> pos[MAXN * MAXN];
umap<int, int> cmp;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(pii s) {
	int x = s.first, y = s.second;
	return x > 0 && y > 0 && x <= n && y <= m;
}

void bfs(pii s) {
	queue<pii> q;
	
	q.push(s);
	vis[s.first][s.second] = true;
	dist[s.first][s.second] = 0;
	
	while (q.size()) {
		pii u = q.front(); q.pop();
		
		if (u == t) return;
		
		if (!visNum[cmp[g[u.first][u.second]]]) {
			for (auto x : pos[cmp[g[u.first][u.second]]]) {
				if (vis[x.first][x.second]) continue;
				vis[x.first][x.second] = true;
				dist[x.first][x.second] = dist[u.first][u.second] + 1;
				q.push(x);
			}
		}
		visNum[cmp[g[u.first][u.second]]] = true;
		
		for (int i = 0; i < 4; i++) {
			pii v = {u.first + dx[i], u.second + dy[i]};
			
			if (!valid(v) || g[v.first][v.second] == 0 || vis[v.first][v.second]) continue;
			
			vis[v.first][v.second] = true;
			dist[v.first][v.second] = dist[u.first][u.second] + 1;
			q.push(v);
		}
	}
}

void testcase() {
	cin >> n >> m;
	
	cin >> s.first >> s.second;
	cin >> t.first >> t.second;
	
	vector<int> comp;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] != 0) comp.push_back(g[i][j]);
		}
	}

	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	
	int time = 0;
	for (auto x : comp) {
		cmp[x] = ++time;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] != 0) pos[cmp[g[i][j]]].push_back({i, j});
		}
	}
	
	bfs(s);
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << dist[i][j] << ' ';
//		}
//		cout << el;
//	}
	
	cout << dist[t.first][t.second];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
