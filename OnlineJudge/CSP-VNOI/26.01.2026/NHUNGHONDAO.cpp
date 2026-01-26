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

struct DSU {
	vector<int> par, sz;
	
	DSU(int n) : par(n), sz(n) {};
	
	void make(int u) {
		par[u] = u;
		sz[u] = 1;
	}
	
	int find(int u) {
		return u == par[u] ? u : par[u] = find(par[u]);
	}
	
	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return false;
		else {
			if (sz[u] < sz[v]) swap(u, v);
			par[v] = u;
			sz[u] += sz[v];
			return true;
		}
	}
};

struct cell {
	int h, i, j; //hiehgt
};

const int MAXN = 1e3 + 5;

int m, n;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int h[MAXN][MAXN];
bool vis[MAXN][MAXN];

int id(int i, int j) {
	return i * n + j;
}

bool valid(int i, int j) {
	return i >= 0 && i < m && j >= 0 && j < n;
}

void testcase() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> h[i][j];
		}
	}
	vector<cell> cells; cells.reserve(m * n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cells.push_back({h[i][j], i, j});
		}
	}
	sort(cells.begin(), cells.end(), [](cell &x, cell &y) {
		return x.h > y.h;
	});
	
	DSU dsu(m * n);
	for (int i = 0; i < m * n; i++) dsu.make(i);
	
	int cnt = 0;
	int res = 0;
	
	int idx = 0;
	while (idx < (int)cells.size()) {
	    int j = idx;
	    int cur_h = cells[idx].h;

	    while (j < (int)cells.size() && cells[j].h == cur_h) {
	        int x = cells[j].i;
	        int y = cells[j].j;
	        vis[x][y] = true;
	        ++cnt;
	        j++;
	    }

	    for (int k = idx; k < j; k++) {
	        int x = cells[k].i;
	        int y = cells[k].j;
	        for (int d = 0; d < 4; d++) {
	            int nx = x + dx[d];
	            int ny = y + dy[d];
	            if (!valid(nx, ny) || !vis[nx][ny]) continue;
	            if (dsu.unite(id(x, y), id(nx, ny))) --cnt;
	        }
	    }

	    res = max(res, cnt);
	
	    idx = j;
	}
	
	cout << res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	ll t = 1; // cin >> t;
	while (t--) testcase();

	return 0;
}
