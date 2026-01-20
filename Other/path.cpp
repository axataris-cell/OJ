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
vector<int> f(MAXN, 0);
bool vis[MAXN];

void dfs(int s) {
	vis[s] = true;
	for (auto u : g[s]) {
		if (!vis[u]) {
			dfs(u);
			f[s] += f[u];
		}
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
	}
	f[1] = 1;
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << f[i] << ' ';
	}
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
