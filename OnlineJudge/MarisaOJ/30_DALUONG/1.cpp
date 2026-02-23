#include <bits/stdc++.h>
#include <chrono>

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

const int MAXN = 5e3 + 5;

int n, r; 

vector<vector<char>> g(MAXN, vector<char>(MAXN, 0));
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(pii u) {
	int x = u.first;
	int y = u.second;
	return x <= n && x > 0 && y <= y && y > 0;
}

void testcase() {
	cin >> n >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	
	queue<pii> q;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (g[i][j] == 'X') {
				q.push({i, j});
				vis[i][j] = true;
			}
		}
	}
	
	while (q.size()) {
		pii u = q.front(); q.pop();
		
		if (dist[u.first][u.second] >= r) continue;
		
		for (int i = 0; i < 4; i++) {
			pii v = {u.first + dx[i], u.second + dy[i]};
			if (valid(v) && !vis[v.first][v.second]) {
				vis[v.first][v.second] = true;
				dist[v.first][v.second] = dist[u.first][u.second] + 1;
				q.push(v);
			}
		}
	}
	
	int res = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[i][j]) ++res;
		}
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
