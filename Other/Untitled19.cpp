#include <bits/stdc++.h>
using namespace std;

static const int MOD = 31011;

struct DSU {
    vector<int> p;
    DSU(int n = 0) : p(n + 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a != b) p[a] = b;
    }
};

struct Edge {
    int u, v;
    long long w;
};

int det(vector<vector<int>> a, int n) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            while (a[j][i]) {
                int t = a[i][i] / a[j][i];
                for (int k = i; k < n; k++) {
                    a[i][k] = (a[i][k] - t * a[j][k]) % MOD;
                    if (a[i][k] < 0) a[i][k] += MOD;
                }
                swap(a[i], a[j]);
                res = (MOD - res) % MOD;
            }
        }
        if (a[i][i] == 0) return 0;
        res = res * a[i][i] % MOD;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto &e : edges) {
        cin >> e.u >> e.v >> e.w;
    }

    sort(edges.begin(), edges.end(),
         [](const Edge &a, const Edge &b) {
             return a.w < b.w;
         });

    DSU dsu(n);
    int ans = 1;

    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && edges[j].w == edges[i].w) j++;

        // Map component -> id
        unordered_map<int, int> id;
        vector<pair<int,int>> useful;
        for (int k = i; k < j; k++) {
            int u = dsu.find(edges[k].u);
            int v = dsu.find(edges[k].v);
            if (u != v) {
                useful.emplace_back(u, v);
                if (!id.count(u)) id[u] = id.size();
                if (!id.count(v)) id[v] = id.size();
            }
        }

        int sz = id.size();
        if (sz > 0) {
            vector<vector<int>> lap(sz, vector<int>(sz, 0));
            for (auto [u, v] : useful) {
                int x = id[u], y = id[v];
                lap[x][x]++;
                lap[y][y]++;
                lap[x][y]--;
                lap[y][x]--;
            }

            // remove last row & column
            vector<vector<int>> mat(sz - 1, vector<int>(sz - 1));
            for (int r = 0; r < sz - 1; r++)
                for (int c = 0; c < sz - 1; c++)
                    mat[r][c] = (lap[r][c] % MOD + MOD) % MOD;

            ans = ans * det(mat, sz - 1) % MOD;
        }

        // Union for Kruskal
        for (int k = i; k < j; k++) {
            dsu.unite(edges[k].u, edges[k].v);
        }

        i = j;
    }

    cout << ans << "\n";
    return 0;
}
