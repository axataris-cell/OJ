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

const int MAXN = 100 + 5;

int n;
string grid[2];
bool visited[2][MAXN];

bool valid(pii v) {
	int x = v.first, y = v.second;
	return x >= 0 && x <= 1 && y >= 0 && y <= n - 1;
}

int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8] = {0, 1, -1, 0, 1, -1, 1, -1};

void bfs(pii s) {
	queue<pii> q;
	
	q.push(s);
	visited[s.first][s.second] = true;
	
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		
		for (int i = 0; i < 8; i++) {
			pii v = {u.first + dx[i], u.second + dy[i]};
			if (valid(v) && !visited[v.first][v.second] && grid[v.first][v.second] == '0') {
				q.push(v);
				visited[v.first][v.second] = true;
			}
		}
	}
}

void testcase() {
	cin >> n;
	cin >> grid[0] >> grid[1];
	
	memset(visited, false, sizeof(visited));
	bfs({0, 0});
	
	if (visited[1][n - 1]) cout << "YES" << el;
	else cout << "NO" << el;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
