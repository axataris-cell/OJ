#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void file() {
	freopen("", "r", stdin);
	freopen("", "w", stdout);
}

const int MAXN = 1e3 + 5;
bool vis[MAXN][MAXN];
int res = 0;

int n, m;
char a[MAXN][MAXN];

bool valid(pii v) {
	return v.first > 0 && v.second > 0 && v.first <= n && v.second <= m;
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(pii s) {
	++res;
	queue<pii> q;
	
	q.push(s);
	vis[s.first][s.second] = true;
	
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			pii u = {v.first + dx[i], v.second + dy[i]};
			if (valid(u) && !vis[u.first][u.second] && a[u.first][u.second] == '.') {
				vis[u.first][u.second] = true;
				q.push(u);
			}
		}
	}
}

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[i][j] && a[i][j] == '.') {
				bfs({i, j});
			}
		}
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
