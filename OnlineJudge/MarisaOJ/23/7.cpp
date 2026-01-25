#include <bits/stdc++.h>
#include <chrono>
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

const int MAXN = 1e5 + 5;

int n, q, a[MAXN], par[MAXN], h[MAXN];
vector<int> g[MAXN];

void dfs(int u, int pre){
    for (int v : g[u]) if (v != pre){
        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
    }
}
void testcase() {
    cin >> n >> q;
    for (int i = 1, u, v; i <= n - 1; ++i){
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    while(q--){
        int u, v, val;
        cin >> u >> v >> val;
        vector<int> nodes;
        while(h[v] > h[u]){
            if (a[v] == 0) a[v] = val;
            nodes.push_back(v);
            v = par[v];
        }
        if (a[u] == 0) a[u] = val;
        for (int v : nodes){
            par[v] = par[u];
        }
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
