#include <bits/stdc++.h>
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

struct DSU {
    int n;
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
        this->n = n;
        parent.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
};

void testcase() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> melt(n, vector<int>(m, -1));
    queue<pii> q;

    vector<pii> swans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 'X') {
                melt[i][j] = 0;
                q.push(make_pair(i, j));
            }
            if (grid[i][j] == 'L') {
                swans.push_back(make_pair(i, j));
            }
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (melt[nx][ny] != -1) continue;
            melt[nx][ny] = melt[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    vector<tuple<int,int,int>> cells;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cells.push_back(make_tuple(melt[i][j], i, j));
        }
    }

    sort(cells.begin(), cells.end());

    DSU dsu(n * m);
    vector<vector<bool>> active(n, vector<bool>(m, false));

    int ax = swans[0].first;
    int ay = swans[0].second;
    int bx = swans[1].first;
    int by = swans[1].second;

    int idA = ax * m + ay;
    int idB = bx * m + by;

    for (int i = 0; i < cells.size(); i++) {
        int day = get<0>(cells[i]);
        int x = get<1>(cells[i]);
        int y = get<2>(cells[i]);

        active[x][y] = true;
        int id1 = x * m + y;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!active[nx][ny]) continue;
            int id2 = nx * m + ny;
            dsu.unite(id1, id2);
        }

        if (dsu.find(idA) == dsu.find(idB)) {
            cout << day << el;
            return;
        }
    }

}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
