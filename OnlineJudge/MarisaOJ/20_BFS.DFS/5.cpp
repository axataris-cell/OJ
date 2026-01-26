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

const int MAXN = 1e3 + 5;

int n, m;

vector<vector<char>> g(MAXN, vector<char>(MAXN));
vector<vector<int>> dist(MAXN, vector<int>(MAXN, -1));
bool vis[MAXN][MAXN];
vector<int> res;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool valid(pii u) {
	int x = u.first, y = u.second;
	return x <= n && x > 0 && y > 0 && y <= m && (g[x][y] == '.' || g[x][y] == 'x');
}

void bfs(int x, int y) {
	queue<pii> q;
	int cnt = 0;
	
	q.emplace(x, y);
	vis[x][y] = true;
	dist[x][y] = 0;
	
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		if (g[u.first][u.second] == 'x') ++cnt;
		for (int i = 0; i < 4; i++) {
			pii v = {u.first + dx[i], u.second + dy[i]};
			if (valid(v) && !vis[v.first][v.second]) {
				vis[v.first][v.second] = true;
				q.push(v);
			}
		}
	}
	if (cnt != 0) res.push_back(cnt);
}

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (valid({i, j}) && !vis[i][j]) bfs(i, j);
		}
	}
	sort(res.begin(), res.end());
	for (auto x : res) cout << x << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
