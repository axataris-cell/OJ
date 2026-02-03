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

/*
5 5
1 1 2 1 2
1 2
2 3
2 4
1 5
1 4 1
1 4 2
1 3 2
1 3 1
5 5 1
*/

const int MAXN = 100000 + 5;

int n, q;
vector<int> adj[MAXN];
int color[MAXN];

int parent[MAXN], depth[MAXN], heavy[MAXN];
int head[MAXN], pos[MAXN], sz[MAXN];
int cur_pos;

vector<unordered_set<int>> seg;

int dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    int maxsz = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int sub = dfs(v, u);
        sz[u] += sub;
        if (sub > maxsz) {
            maxsz = sub;
            heavy[u] = v;
        }
    }
    return sz[u];
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos;

    if (heavy[u]) decompose(heavy[u], h);

    for (int v : adj[u]) {
        if (v != parent[u] && v != heavy[u]) {
            decompose(v, v);
        }
    }
}

void build(int idx, int l, int r, vector<int>& base) {
    if (l == r) {
        seg[idx].insert(base[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(idx<<1, l, mid, base);
    build(idx<<1|1, mid+1, r, base);

    seg[idx] = seg[idx<<1];
    seg[idx].insert(seg[idx<<1|1].begin(), seg[idx<<1|1].end());
}

bool query_seg(int idx, int l, int r, int ql, int qr, int c) {
    if (qr < l || r < ql) return false;
    if (ql <= l && r <= qr) {
        return seg[idx].count(c);
    }
    int mid = (l + r) >> 1;
    return query_seg(idx<<1, l, mid, ql, qr, c) || query_seg(idx<<1|1, mid+1, r, ql, qr, c);
}

bool query_path(int u, int v, int c) {
    while (head[u] != head[v]) {
        if (depth[head[u]] < depth[head[v]]) swap(u, v);
        if (query_seg(1, 1, n, pos[head[u]], pos[u], c)) return true;
        u = parent[head[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    return query_seg(1, 1, n, pos[u], pos[v], c);
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> color[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    decompose(1, 1);

    vector<int> base(n + 1);
    for (int i = 1; i <= n; i++) base[pos[i]] = color[i];

    seg.resize(4 * (n + 1));
    build(1, 1, n, base);

    while (q--) {
        int u, v, c;
        cin >> u >> v >> c;
        cout << (query_path(u, v, c) ? '1' : '0');
    }
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); file();

	int t = 1; //cin >> t;
	while (t--) testcase();

	return 0;
}
