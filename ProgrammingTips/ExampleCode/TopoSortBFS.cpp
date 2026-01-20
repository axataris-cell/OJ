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
vector<int> g[MAXN];
vector<int> deg(MAXN, 0);
vector<int> topo;

int n, m;

void toposort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		auto u = q.front(); q.pop();
		topo.push_back(u);
		
		for (auto v : g[u]) {
			--deg[v];
			if (deg[v] == 0) q.push(v);
		}
	}
}

void testcase() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		++deg[b];
	}
	toposort();
	// Nếu các đỉnh không cháy hết thì có nghĩa là có chu kì nên không thể toposort cho DAG
	if (topo.size() < n) {
		cout << -1;
		return;
	}
	for (auto x : topo) cout << x << ' ';
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
