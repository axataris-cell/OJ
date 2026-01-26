#include <bits/stdc++.h>
#include <chrono>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

#define int long long

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

const int MAXN = 1e2 + 5;

int n;

int g[MAXN][MAXN][MAXN];
int dist[MAXN][MAXN][MAXN];

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

struct pos {
	int x, y, z;
	int w;
};

struct comp {
	bool operator()(pos &x, pos& y) const {
		return x.w > y.w;
	}
};

bool valid(pos u) {
	return u.x > 0 && u.y > 0 && u.z > 0 && u.x <= n && u.y <= n && u.z <= n;
}

void dijkstra(int sx, int sy, int sz) {
	pqueue<pos, vector<pos>, comp> pq;
	
	pq.push({sx, sy, sz, 0});
	dist[sx][sy][sz] = 0;
	
	while (pq.size()) {
		pos x = pq.top(); pq.pop();
		
		if (x.w > dist[x.x][x.y][x.z]) continue;
		
		for (int i = 0; i < 6; i++) {
			pos y = {x.x + dx[i], x.y + dy[i], x.z + dz[i], 0};
			if (valid(y) && dist[y.x][y.y][y.z] > dist[x.x][x.y][x.z] + g[y.x][y.y][y.z]) {
				dist[y.x][y.y][y.z] = dist[x.x][x.y][x.z] + g[y.x][y.y][y.z];
				pq.push({y.x, y.y, y.z, dist[y.x][y.y][y.z]});
			}
		}
	}
}

void testcase() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cin >> g[i][j][k];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				dist[i][j][k] = LLONG_MAX;
			}
		}
	}
	dijkstra(1, 1, 1);
	cout << dist[n][n][n];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
