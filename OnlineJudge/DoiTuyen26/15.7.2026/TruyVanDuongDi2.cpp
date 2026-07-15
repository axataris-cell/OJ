#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 2e9;
constexpr int MAXN = 2e5 + 5;

vector<int> g[MAXN];
int h[MAXN], heavy[MAXN], pos[MAXN], sz[MAXN], head[MAXN];
int v_map[MAXN], par[MAXN], initial_val[MAXN];

int ST[MAXN * 2];
int n, q, timeDfs;

void dfs(int u, int p) {
    sz[u] = 1;
    heavy[u] = 0;
    int mx = 0;
    for (int v : g[u]) {
        if (v == p) continue;
        h[v] = h[u] + 1;
        par[v] = u;
        dfs(v, u);
        sz[u] += sz[v];
        if (sz[v] > mx) {
            mx = sz[v];
            heavy[u] = v;
        }
    }
}

void decompose(int u, int h_head) {
    pos[u] = ++timeDfs;
    v_map[timeDfs] = initial_val[u];
    head[u] = h_head;

    if (heavy[u] != 0) decompose(heavy[u], h_head);

    for (int v : g[u]) {
        if (v == par[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

void build() {
    for (int i = 0; i < n; i++) ST[i + n] = v_map[i + 1];
    for (int i = n - 1; i > 0; i--) ST[i] = max(ST[i << 1], ST[i << 1 | 1]);
}

void updateST(int p, int val) {
    p--;
    for (ST[p += n] = val; p > 1; p >>= 1) {
        ST[p >> 1] = max(ST[p], ST[p ^ 1]);
    }
}   

int queryST(int l, int r) {
    l--;
    r--;
    int res = -INF;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, ST[l++]);
        if (r & 1) res = max(res, ST[--r]);
    }
    return res;
}

int queryHLD(int a, int b) {
    int res = -INF;
    while (head[a] != head[b]) {
        if (h[head[a]] < h[head[b]]) swap(a, b);
        res = max(res, queryST(pos[head[a]], pos[a]));
        a = par[head[a]];
    }
    if (pos[a] > pos[b]) swap(a, b);
    res = max(res, queryST(pos[a], pos[b]));
    return res;
}

void testcase() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> initial_val[i];
        g[i].clear();
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    timeDfs = 0;
    h[1] = 1;
    dfs(1, 1);
    decompose(1, 1);
    build();

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            updateST(pos[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << queryHLD(a, b) << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) testcase();

    return 0;
}