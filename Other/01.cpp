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
#define int long long

const int MAXN = 1005;

int n, m;

int g[MAXN][MAXN];
int dist[MAXN][MAXN];

bool valid(pii s) {
	int x = s.first, y = s.second;
	return x > 0 && x <= n && y >= 0 && y <= m;
}

struct point {
	int x; int y;
	int dist;
};

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void bfs(pii s) {
	deque<point> dq;
	
	dq.push_front({s.first, s.second, 0});
	dist[s.first][s.second] = 0;
	
	while (dq.size()) {
		point a = dq.front(); dq.pop_front();
		
		if (a.dist > dist[a.x][a.y]) continue;
		
		for (int i = 0; i < 4; i++) {
			pii b = {a.x + dx[i], a.y + dy[i]};
			if (!valid(b) || g[b.first][b.second] == 0) continue;
			
			if (g[b.first][b.second] == g[a.x][a.y]) {
				if (dist[b.first][b.second] > dist[a.x][a.y]) {
					dist[b.first][b.second] = dist[a.x][a.y];
					dq.push_front({b.first, b.second, dist[b.first][b.second]});
				}
			} else {
				if (dist[b.first][b.second] > dist[a.x][a.y] + 1) {
					dist[b.first][b.second] = dist[a.x][a.y] + 1;
					dq.push_back({b.first, b.second, dist[b.first][b.second]});
				}
			}
		}
	}
	
}

void testcase() {
	cin >> n >> m;
	
	pii s; cin >> s.first >> s.second;
	pii t; cin >> t.first >> t.second;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			dist[i][j] = LINF;
		}
	}
	
	bfs(s);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << el;
	}
	
	cout << dist[t.first][t.second];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
