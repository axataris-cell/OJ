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

const int MAXN = 1e5 + 5;
vector<int> g[MAXN];
vector<vector<int>> dist(MAXN, vector<int>(2, -2));

void bfs(int s) {
	queue<pii> q;
	
	q.push({s, 0});
	dist[s][0] = 0;
	
	while (!q.empty()) {
		int u = q.front().first;
		int k = q.front().second;
		q.pop();
		for (auto v : g[u]) {
			if (dist[v][1 - k] == -2) {
				dist[v][1 - k] = dist[u][k] + 1;
				q.push({v, 1 - k});
			}
		}
	}
}

void testcase() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	bfs(s);
	
	cout << dist[t][0]/2;
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
