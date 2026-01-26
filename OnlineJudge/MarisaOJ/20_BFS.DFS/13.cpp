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

void debug_time(const string& label = "") {
    static auto start = chrono::steady_clock::now();
    auto now = chrono::steady_clock::now();
    double ms = chrono::duration<double, milli>(now - start).count();
    cerr << "[TIME] " << label << ": " << ms << " ms\n";
}

const int MAXN = 505;

int n, m;

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dead[MAXN][MAXN];

bool valid(pii u) {
	int x = u.first, y = u.second;
	return x > 0 && y > 0 && x <= n && y <= m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(pii s) {
	queue<pii> q;
	
	q.push(s);
	vis[s.first][s.second] = true;
	
	while (q.size()) {
		pii u = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			pii v = {u.first + dx[i], u.second + dy[i]};
			if (!valid(v) || g[v.first][v.second] == 'B') {
				++dead[u.first][u.second];
			} else if (valid(v) && g[v.first][v.second] == 'W') {
				++dead[u.first][u.second];
				if (!vis[v.first][v.second]) {
					vis[v.first][v.second] = true;
					q.push(v);
				}
			}
		}
	}
}

int check(pii s) {
	queue<pii> q;
	bool ok = true;
	int cnt = 1;
	
	q.push(s);
	vis[s.first][s.second] = true;
	
	while (q.size()) {
		pii u = q.front(); q.pop();
		if (dead[u.first][u.second] < 4) ok = false;
		for (int i = 0; i < 4; i++) {
			pii v = {u.first + dx[i], u.second + dy[i]};
			if (valid(v) && g[v.first][v.second] == 'W' && !vis[v.first][v.second]) {
				vis[v.first][v.second] = true;
				++cnt;
				q.push(v);
			}
		}
	}
	if (!ok) return 0;
	else return cnt;
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
			if (!vis[i][j] && g[i][j] == 'W') {
				bfs({i, j});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			vis[i][j] = false;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			cout << dead[i][j] << ' ';
//		}
//		cout << el;
//	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && g[i][j] == 'W') {
				res += check({i, j});
			}
		}
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	debug_time();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
