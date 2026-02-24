#include <bits/stdc++.h>
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

const int MAXN = 2005;

int n;

char g[MAXN][MAXN];
int dist[MAXN][MAXN][4];

struct dat {
	int x, y;
	int k;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= n;
}

void testcase() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
			for (int k = 0; k < 4; k++) {
				dist[i][j][k] = INF;
			}
		}
	}
	
	deque<dat> dq; // cell, direc
	// Bac - 0
	// Dong - 1
	// Nam - 2
	// Tay - 3
	dq.push_front({1, 1, 2});
	dist[1][1][2] = 0;
	
	
	while (dq.size()) {
		dat cur = dq.front(); dq.pop_front();
		int x = cur.x;
		int y = cur.y;
		int k = cur.k;
		
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (valid(nx, ny) && g[nx][ny] == '.' && dist[nx][ny][k] > dist[x][y][k]) {
			dist[nx][ny][k] = dist[x][y][k];
			dq.push_front({nx, ny, k});
		}
		
		if (dist[x][y][((k - 1) % 4 + 4) % 4] > dist[x][y][k] + 1) {
			dist[x][y][((k - 1) % 4 + 4) % 4] = dist[x][y][k] + 1;
			dq.push_back({x, y, ((k - 1) % 4 + 4) % 4});
		}
		
		if (dist[x][y][((k + 1) % 4 + 4) % 4] > dist[x][y][k] + 1) {
			dist[x][y][((k + 1) % 4 + 4) % 4] = dist[x][y][k] + 1;
			dq.push_back({x, y, ((k + 1) % 4 + 4) % 4});
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dist[i][j] << ' ';
//		}
//		cout << el;
//	}
	int res = min({dist[n][n][0], dist[n][n][1], dist[n][n][2], dist[n][n][3]});
	
	if (res == INF) cout << -1;
	else cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
