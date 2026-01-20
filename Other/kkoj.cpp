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
bool vis[MAXN];

int res = 0;

void bfs(int s) {
	++res;
	queue<int> q;
	
	q.push(s);
	vis[s] = true;
	
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		
		for (auto v : g[u]) {
			if (!vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) bfs(i);
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
