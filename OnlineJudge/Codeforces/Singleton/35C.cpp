#include <bits/stdc++.h>
using namespace std;
#define int long long
#define el '\n'
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
using pii=pair<int,int>;
#define FILENAME "input"
#define fastio ios_base::sync_with_stdio(false),cin.tie(nullptr);
void file(){freopen("input.txt","r", stdin),freopen("output.txt","w", stdout);}
const int INF=4e18,MAXN=2e5+5,LOG=20,MOD=1e9+7,BASE=113,BLOCK=400;

int dist[2005][2005];
bool vis[2005][2005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void testcase() {
	int n, m; cin >> n >> m;
	int k; cin >> k;
	
	queue<pii> q;
	for (int i = 1; i <= k; i++) {
		int x, y; cin >> x >> y;
		vis[x][y] = true;
		dist[x][y] = 0;
		q.push({x, y});
	}
	
	auto valid = [&](int x, int y) -> bool {
		return x <= n &&  y <= m && x > 0 && y > 0;
	};
	
	int last = 0;
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		last = max(last, dist[x][y]);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!valid(nx, ny) || vis[nx][ny]) continue;
			vis[nx][ny] = true;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == last) {
				cout << i << ' ' << j;
				return;
			}
		}
	}
}
int32_t main() {
    fastio file();
    int t=1;//cin>>t;
    while(t--)testcase();
    return 0;
}


