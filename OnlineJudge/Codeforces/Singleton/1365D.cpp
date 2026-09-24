#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME ""
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){if(FILE*f=fopen(FILENAME".INP","r")) fclose(f),freopen(FILENAME".INP","r", stdin),freopen(FILENAME".OUT","w", stdout);}
const int INF=2e9,MAXN=2e5+5,LOG=30,MOD=1e9+7,BASE=113,BLOCK=400;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void testcase() {
	int n, m; cin >> n >> m;
	vector<vector<char>> g(n + 1, vector<char>(m + 1, 0));
	int cntGood = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
			if (g[i][j] == 'G') ++cntGood;
		}
	}
	auto valid =[&](int x, int y) ->bool {
		return x > 0 && y > 0 && x <= n && y <= m;
	};
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) if (g[i][j] == 'B') {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (!valid(nx, ny) || g[nx][ny] == '#' || g[nx][ny] == 'B') continue;
				if (g[nx][ny] == 'G') {
					cout << "NO" << el;
					return;
				}
				g[nx][ny] = '#';
			}
		}
	}
	
	queue<pii> q;
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, false));
	if (g[n][m] != '#') {
		q.push({n, m});
		vis[n][m] = true;
	}
	int after = 0;
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (g[x][y] == 'G') ++after;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!valid(nx, ny) || g[nx][ny] == '#' || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	
	cout << (after != cntGood ? "NO" : "YES") << el;
}
int32_t main() {
    fastio file();
    int t=1;cin>>t;
    while(t--)testcase();
    return 0;
}

