#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'
#define INF 2e9
#define LINF 4e18

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

const int MAXN = 505;

int n, m, s, k;

char g[MAXN][MAXN];
int adj[MAXN][MAXN];

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool vis[MAXN][MAXN];
bool deac[MAXN][MAXN];

bool check(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= m;
}

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!check(nx, ny) || g[nx][ny] != '.') continue;
		++adj[x][y];
		if (!vis[nx][ny]) dfs(nx, ny);
	}
}

/*
4 4 4
#..#
...#
.###
....
*/
void testcase() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == '.') ++s;
		}
	}
	for (int i = 1; i <= n; i++) {
		bool d = false;
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == '.') {
				dfs(i, j);
				d = true;
				break;
			}
		}
		if (d) break;
	}
	int cnt = 0;
	while (cnt < k) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] != '.') continue;
				
				
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << adj[i][j];
		}
		cout << el;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << g[i][j];
		}
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
