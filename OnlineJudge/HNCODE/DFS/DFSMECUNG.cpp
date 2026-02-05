#include <bits/stdc++.h>
#include <chrono>

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

const int MAXN = 1e3 + 5;

int n, m; 

char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
pii par[MAXN][MAXN];

pii posA, posB;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool valid(pii u) {
	auto [i, j] = u;
	return i >= 1 && i <= n && j >= 1 && j <= m && g[i][j] != '#';
}

void dfs(pii s) {
	vis[s.first][s.second] = true;
	for (int i = 0; i < 4; i++) {
		pii v = {s.first + dx[i], s.second + dy[i]};
		if (valid(v) && !vis[v.first][v.second]) {
			par[v.first][v.second] = s;
			dfs(v);
		}
	}
}

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			par[i][j] = {-1, -1};
			cin >> g[i][j];
			if (g[i][j] == 'A') posA = {i, j};
			if (g[i][j] == 'B') posB = {i, j};
		}
	}
	dfs(posA);
	if (!vis[posB.first][posB.second]) {
		cout << "NO";
		return;
	}
	cout << "YES" << el;
	pii cur = posB;
	vector<char> path;
	while (cur.first != -1 && cur.second != -1) {
		pii next = par[cur.first][cur.second];
		if (next.first - cur.first == 1) path.push_back('U');
		if (cur.first - next.first == 1) path.push_back('D');
		if (next.second - cur.second == 1) path.push_back('L');
		if (cur.second - next.second == 1) path.push_back('R');
		cur = next;
	}
	reverse(path.begin(), path.end());
	cout << path.size() << el;
	for (auto x : path) cout << x;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
