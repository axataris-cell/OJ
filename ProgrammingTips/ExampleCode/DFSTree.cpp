#include <bits/stdc++.h>
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define ll long long
#define ld long double
#define el '\n'

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
int num[MAXN], low[MAXN], tail[MAXN];

int time = 0;
void dfs(int u, int p) {
	num[u] = low[u] = ++time;
	for (int v : g[u]) {
		if (v == p) continue;
		if (!num[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else low[u] = min(low[u], num[v]);
	}
	tail[u] = time;
}

void testcase() {
	
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	file();

	ll t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
