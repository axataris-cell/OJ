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

const int MAXN = 1e5 + 5;

vector<int> g[MAXN];
bool vis[MAXN];
vector<int> res;

bool dfs(int s, int t) {
	if (s == t) {
		res.push_back(t);
		return true;
	}
	vis[s] = true;
	sort(g[s].begin(), g[s].end());
	for (int v : g[s]) {
		if (!vis[v]) {
			bool b = dfs(v, t);
			if (b) {
				res.push_back(s);
				return true;
			}
		}
	}
	return false;
}

void testcase() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bool k = dfs(s, t);
	reverse(res.begin(), res.end());
	for (auto x : res) cout << x << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
