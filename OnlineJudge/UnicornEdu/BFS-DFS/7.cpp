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

void dfs(int s) {
	vis[s] = true;
	
	for (int v : g[s]) {
		if (!vis[v]) dfs(v);
	}
}

void testcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector<int> res;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			res.push_back(i);
			dfs(i);
		}
	}
	
	if (res.size() > 1) {
		cout << res.size() - 1 << el;
		for (int i = 0; i < res.size() - 1; i++) {
			cout << res[i] << ' ' << res[i + 1] << el;
		}
	} else cout << 0;
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
