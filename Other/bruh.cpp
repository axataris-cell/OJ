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

const int MAXN = 100000 + 5;
const int LOG = 17;

int n, m;
vector<int> adj[MAXN];
int color[MAXN];

int parent[LOG+1][MAXN], depth[MAXN];
int tin[MAXN], timer;

int bit[MAXN];

void add(int i, int v) {
    for (; i <= n; i += i & -i) bit[i] += v;
}

int sum(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}

void dfs(int u, int p) {
    parent[0][u] = p;
    tin[u] = ++timer;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int u, int v) {
	if (depth[u] != depth[v]) {
		if (depth[u] < depth[v]) swap(u, v);
		
	    int diff = depth[u] - depth[v];
	    for (int i = 0; i <= LOG; i++) {
	        if (diff & (1 << i)) u = parent[i][u];
		}
	}

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--) {
        if (parent[i][u] != parent[i][v]) {
            u = parent[i][u];
            v = parent[i][v];
        }
    }
    return parent[0][u];
}

struct query {
    int u, v, id;
};

vector<query> cuto[MAXN];
int ans[MAXN];

void testcase() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> color[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
	
	//lca spat tablet
    for (int i = 1; i <= LOG; i++) {
        for (int v = 1; v <= n; v++) {
            parent[i][v] = parent[i-1][parent[i-1][v]];
    	}
    }

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        cuto[c].push_back({u, v, i});
    }

    for (int c = 1; c <= n; c++) {
        for (int i = 1; i <= n; i++) {
            if (color[i] == c) add(tin[i], 1);
        }
        
        for (auto &q : cuto[c]) {
            int u = q.u, v = q.v;
            int w = lca(u, v);

            int cnt = sum(tin[u]) + sum(tin[v]) - 2 * sum(tin[w]);
            if (color[w] == c) cnt++;

            ans[q.id] = (cnt > 0);
        }

        for (int i = 1; i <= n; i++) {
            if (color[i] == c) add(tin[i], -1);
        }
    }

    for (int i = 1; i <= m; i++) cout << ans[i];
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
