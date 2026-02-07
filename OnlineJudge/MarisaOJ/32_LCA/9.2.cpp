#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
const int LOGN = 18;

vector<int> adj[MAXN];
int up[MAXN][LOGN];
int depth[MAXN];
int f1[MAXN], f2[MAXN], child1[MAXN];
int g[MAXN];
int n, q;

// DFS thứ nhất: Tính độ sâu, tổ tiên (LCA) và khoảng cách xa nhất trong cây con
void dfs1(int u, int p, int d) {
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i < LOGN; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    f1[u] = f2[u] = 0;
    child1[u] = -1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u, d + 1);
        int dist = f1[v] + 1;
        if (dist > f1[u]) {
            f2[u] = f1[u];
            f1[u] = dist;
            child1[u] = v;
        } else if (dist > f2[u]) {
            f2[u] = dist;
        }
    }
}

// DFS thứ hai: Tính khoảng cách xa nhất ra ngoài cây con (Rerooting DP)
void dfs2(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        if (v == child1[u]) {
            g[v] = max(g[u], f2[u]) + 1;
        } else {
            g[v] = max(g[u], f1[u]) + 1;
        }
        dfs2(v, u);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOGN - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int get_kth_ancestor(int u, int k) {
    for (int i = 0; i < LOGN; i++) {
        if ((k >> i) & 1) u = up[u][i];
    }
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> q)) return 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 1, 0);
    g[1] = 0;
    dfs2(1, 1);

    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca = get_lca(u, v);
        int d_uv = depth[u] + depth[v] - 2 * depth[lca];
        int k = (d_uv - 1) / 2;
        int d_vl = depth[v] - depth[lca];

        int mid, ans;

        if (k < d_vl) {
            // mid nằm trên đoạn v -> lca
            mid = get_kth_ancestor(v, k);
            // Thành phần liên thông là cây con của mid
            ans = (d_uv - k) + f1[mid];
        } else {
            // mid nằm trên đoạn lca -> u
            int dist_u_mid = d_uv - k;
            mid = get_kth_ancestor(u, dist_u_mid);
            int p_mid = get_kth_ancestor(u, dist_u_mid - 1);
            
            // Thành phần liên thông là toàn bộ cây trừ đi nhánh chứa u
            int max_d_mid;
            if (child1[mid] == p_mid) {
                max_d_mid = max(g[mid], f2[mid]);
            } else {
                max_d_mid = max(g[mid], f1[mid]);
            }
            ans = dist_u_mid + max_d_mid;
        }
        cout << ans << "\n";
    }

    return 0;
}