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

#define int long long

// Đề bài: Cho một cây gồm n đỉnh và mỗi đỉnh có 1 giá trị cho trước. Cho q truy vấn:
// Truy vấn loại 1: Cộng thêm vào các đỉnh trên đường đi đơn từ u -> v một giá trị x.
// Truy vấn loại 2: In ra tổng tất cả giá trị trên đỉnh từ u -> v

const int MAXN = 2e5 + 5;

int n;

vector<int> val(MAXN, 0);
vector<int> depth(MAXN, 0), sz(MAXN, 1), heavy(MAXN, 0), par(MAXN, 0);
vector<int> pos(MAXN, 0), arr(MAXN, 0), head(MAXN, 0);
vector<int> ST(4 * MAXN, 0), lz(MAXN, 0);
vector<int> g[MAXN];

void dfs(int u, int p) {
    int msz = 0;
    int best = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
        if (msz < sz[v]) {
            msz = sz[v];
            best = v;
        }
    }
    heavy[u] = best;
}

int timeDfs = 0;
void decompose(int u, int h) {
    pos[u] = ++timeDfs;
    arr[timeDfs] = val[u];
    head[u] = h;

    if (heavy[u] != 0) decompose(heavy[u], h);

    for (int v : g[u]) {
        if (v == heavy[u] || v == par[u]) continue;
        decompose(v, v);
    }
}

void build(int id, int l, int r) {
	if (l == r) {
		ST[id] = arr[l];
		return;
	}
	
	int mid = (l + r) / 2;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

void pushSeg(int id, int l, int r) {
	if (lz[id] == 0) return;
	
	int mid = (l + r) / 2;
	
	ST[id << 1] += (mid - l + 1) * lz[id];
	lz[id << 1] += lz[id];
	
	ST[id << 1 | 1] += (r - mid) * lz[id];
	lz[id << 1 | 1] += lz[id];
	
	lz[id] = 0;
}

void updateSeg(int id, int l, int r, int x, int y, int val) {
	if (l > y || r < x) return;
	if (x <= l && r <= y) {
		ST[id] += (r - l + 1) * val;
		lz[id] += val;
		return;
	}
	int mid = (l + r) / 2;
	pushSeg(id, l, r);
	
	updateSeg(id << 1, l, mid, x, y, val);
	updateSeg(id << 1 | 1, mid + 1, r, x, y, val);
	
	ST[id] = ST[id << 1] + ST[id << 1 | 1];
}

int querySeg(int id, int l, int r, int x, int y) {
	if (l > y || r < x) return 0;
	if (x <= l && r <= y) {
		return ST[id];
	}
	int mid = (l + r) / 2;
	pushSeg(id, l, r);
	
	return querySeg(id << 1, l, mid, x, y) + querySeg(id << 1 | 1, mid + 1, r, x, y);
}

void update(int u, int v, int val) {
	while (head[u] != head[v]) {
		if (depth[head[u]] < depth[head[v]]) swap(u, v);
		updateSeg(1, 1, n, pos[head[u]], pos[u], val);
		u = par[head[u]];
	}
	if (depth[u] > depth[v]) swap(u, v);
	updateSeg(1, 1, n, pos[u], pos[v], val);
}

int query(int u, int v) {
	int res = 0;
	while (head[u] != head[v]) {
		if (depth[head[u]] < depth[head[v]]) swap(u, v);
		res += querySeg(1, 1, n, pos[head[u]], pos[u]);
		u = par[head[u]];
	}
	if (depth[u] > depth[v]) swap(u, v);
	res += querySeg(1, 1, n, pos[u], pos[v]);
	
	return res;
}

/*
11
5 7 9 10 0 -9 4 23 67 -5 -2
1 2
2 3
2 4
3 5
3 6
4 7
7 8
8 9
8 10
8 11
*/

void testcase() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 1);

    decompose(1, 1);

    build(1, 1, n);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x, y, v; cin >> x >> y >> v;
            update(x, y, v);
        } else {
            int x, y; cin >> x >> y;
            cout << query(x, y) << el;
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
