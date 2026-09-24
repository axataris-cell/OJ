#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

constexpr int INF = 2e9;
constexpr ll LINF = 4e18;

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

const int MAXN = 2e5 + 5;

vector<int> g[MAXN];
vector<int> dist(MAXN, 0);
vector<int> cnt(MAXN, 0);
int leaf = 0;

void dfs1(int u, int p) {
	bool child = false;
	for (int v : g[u]) {
		if (v == p) continue;
		child = true;
		dfs1(v, u);
	}
	if (child == false) {
		cnt[p]++;
		cnt[u]++;
	}
}

void dfs2(int u, int p) {
	bool child = 0;
	for (int v : g[u]) {
		if (v == p) continue;
		child = true;
		dist[v] = dist[u] + 1;
		
		dfs2(v, u);
	}
	if (!child && dist[u] > 1) {
		++leaf;
	}
}

void testcase() {
	int n; cin >> n;
	leaf = 0;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		dist[i] = 0;
		cnt[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (n == 2) {
		cout << 0 << el;
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (g[i].size() >= 2) {
			dfs1(i, i);
			break;
		}
	}
	int mxs = -1;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (mxs < cnt[i]) {
			idx = i;
			mxs = cnt[i];
		} 
	}
	
//	for (int i = 1; i <= n; i++) cerr << cnt[i] << ' ';
	
	dfs2(idx, idx);
	
	cout << leaf << el;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; cin >> t;
	while (t--) testcase();

	return 0;
}
