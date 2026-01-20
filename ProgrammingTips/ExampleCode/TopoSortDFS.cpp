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
const int MAXN = 2e5 + 5;
vector<int> g[MAXN], deg(MAXN, 0), topo;
vector<int> vis(MAXN, 0); bool cyclic = false;
// int vis = 3 màu trạng thái gồm: 0 - chưa thăm, 1 - đang thăm và 2 - đã thăm

void topodfs(int s) {
	vis[s] = 1;
	for (auto u : g[s]) {
		if (!vis[u]) {
			topodfs(u);
			if (cyclic) return;
		} else if (vis[u] == 1) {
			cyclic = true;
			return;
		}
	}
	vis[s] = 2;
	topo.push_back(s);
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		++deg[b];
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && deg[i] == 0) {
			topodfs(i);
			if (cyclic) {
				cout << -1;
				return;
			}
		}
	}
	reverse(topo.begin(), topo.end());
	for (auto x : topo) cout << x << ' ';
}

/*
15 17
1 2
1 3
3 2
3 9
3 4
9 4
4 5
4 8
5 6
5 7
9 13
13 14
13 15
12 13
10 9
11 10
11 12
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
